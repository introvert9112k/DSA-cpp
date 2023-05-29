class Solution {
private : 
   int recursion(int m,int n,vector<vector<int>>& grid)
   {
       if(m == 0 && n == 0) return grid[0][0];
       if(m <  0 || n < 0) return INT_MAX;
       int up   = recursion(m-1,n,grid);
       int left = recursion(m,n-1,grid);
       return grid[m][n] + min(up,left);
   }
   int memoization(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp)
   {
       if(m == 0 && n == 0) return grid[0][0];
       if(m <  0 || n < 0) return INT_MAX;
       if(dp[m][n] != -1) return dp[m][n];
       int up   = memoization(m-1,n,grid,dp);
       int left = memoization(m,n-1,grid,dp);
       return dp[m][n] = (grid[m][n] + min(up,left));
   }
   int Tabulation(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp)
   {
       dp[0][0] = grid[0][0];
       for(int i = 0; i<=m; ++i)
       {
           for(int j = 0; j<=n; ++j)
           {
               if(i == 0 && j == 0) continue;
               int up   = i-1 >= 0 ? dp[i-1][j] : INT_MAX;
               int left = j-1 >= 0 ? dp[i][j-1] : INT_MAX;
               dp[i][j] = grid[i][j] + min(up,left);
           }
       }
       return dp[m][n];
   }
   int spaceOptimization(int m,int n,vector<vector<int>>& grid)
   {
        vector<int> curr(n+1),prev(n+1);
        curr[0] = grid[0][0];
        for(int i = 0; i<=m; ++i)
        {
            for(int j = 0; j<=n; ++j)
            {
                if(i == 0 && j == 0) continue;
                int up   = i-1 >= 0 ? prev[j] : INT_MAX;
                int left = j-1 >= 0 ? curr[j-1] : INT_MAX;
                curr[j] = grid[i][j] + min(up,left);
            }
            prev = curr;
        }
        return prev[n];
   }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return recursion(m-1,n-1,grid);
        // return memoization(m-1,n-1,grid,dp);
        // return Tabulation(m-1,n-1,grid,dp);
        return spaceOptimization(m-1,n-1,grid);
    }
};