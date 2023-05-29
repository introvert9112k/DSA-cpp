class Solution {
private : 
  /*
    Time Complexity : O(n*3^m)
    We take each cell in the last row, and do the recursion calls, at each step in the recursion 
    there are 3 calls, The height of the recursive tree is m. Hence there are $3^m$ recursive calls
    totally.. Each of cell in last row has $ 3^m $ recursive calls, so TC is $O(n*3^m)$ 
    
    Space Complexity:  O(m) There are atmost m recursive calls waiting in stack.
  */
  int recursion(int m,int n,vector<vector<int>>& matrix)
  {
      if(m < 0 || n < 0 || n >= matrix[0].size()) return 1e9;
      if(m == 0) return matrix[m][n];
      int up    = recursion(m-1,n,matrix);
      int left  = recursion(m-1,n-1,matrix);
      int right = recursion(m-1,n+1,matrix);
      return matrix[m][n]  + min({up,left,right});
  }
  /*
    Time Complexity: $O(m*n)$ There at most m*n dp states.
    Space Complexity: $O(m*n) + O(m)$ 
    Space for the dp array and the recursion stack space.
  */
  int memoization(int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp)
  {
      if(m < 0 || n < 0 || n >= matrix[0].size()) return 1e9;
      if(m == 0) return matrix[m][n];
      if(dp[m][n] != -1) return dp[m][n];
      int up    = memoization(m-1,n,matrix,dp);
      int left  = memoization(m-1,n-1,matrix,dp);
      int right = memoization(m-1,n+1,matrix,dp);
      return dp[m][n] = matrix[m][n]  + min({up,left,right});
  }
  /*
    Time Complexity: $O(m*n)$ There at most m*n dp states.
    Space Complexity: $O(m*n)$
    Space for the DP array 
  */
  int Tabulation(vector<vector<int>>& matrix)
  {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int ans = INT_MAX;
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(i == 0) dp[i][j] = matrix[i][j];
                else 
                {
                    int up    = dp[i-1][j];
                    int left  = (j-1 >= 0) ? dp[i-1][j-1] : 1e9;
                    int right = (j+1 < n) ? dp[i-1][j+1] : 1e9;
                    dp[i][j] = matrix[i][j] + min({up,left,right});
                }
                if(i == m-1)
                  ans = min(ans,dp[i][j]);
            }
        }
        return ans;
  }
  /*
    Time Complexity: $O(m*n)$ There at most m*n dp states.
    Space Complexity: $O(2n)$
    Space for the curr and prev array 
  */
  int spaceOptimization(vector<vector<int>>& matrix)
  {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> curr(n),prev(n);
        int ans = INT_MAX;
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(i == 0) curr[j] = matrix[i][j];
                else 
                {
                    int up    = prev[j];
                    int left  = (j-1 >= 0) ? prev[j-1] : 1e9;
                    int right = (j+1 < n) ? prev[j+1] : 1e9;
                    curr[j] = matrix[i][j] + min({up,left,right});
                }
                if(i == m-1)
                  ans = min(ans,curr[j]);
            }
            prev = curr;
        }
        return ans;
  }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // int minimumPathSum = INT_MAX;
        // for(int i = 0; i<n; ++i)
        //    minimumPathSum = min(minimumPathSum,memoization(m-1,i,matrix,dp));
        // return minimumPathSum;

        // return Tabulation(matrix);

        return spaceOptimization(matrix);
    }
};