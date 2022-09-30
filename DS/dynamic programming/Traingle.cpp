class Solution
{
public:
    /*
       Time Complexity : O(2^(No of elements in traingle))
       For each element there are two choices whether to go down or diagonal
       Space Complexity : O(N)
       Recursion stack Space. At most N calls will be waiting in the stack
    */
    int recursion(int i, int j, int n, vector<vector<int>> &triangle)
    {
        if (i == n - 1)
            return triangle[n - 1][j];
        int down = triangle[i][j] + recursion(i + 1, j, n, triangle);
        int diagonal = triangle[i][j] + recursion(i + 1, j + 1, n, triangle);
        return min(down, diagonal);
    }
    /*
      Time Complexity : O(NxN)
      Eliminating overlapping subProblems reduces the complexity to NxN
      Space complexity : O(N) + O(NxN)
      Recursion stack space and the DP Array space.
    */
    int memoziation(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return triangle[n - 1][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = triangle[i][j] + memoziation(i + 1, j, n, triangle, dp);
        int diagonal = triangle[i][j] + memoziation(i + 1, j + 1, n, triangle, dp);
        return dp[i][j] = min(down, diagonal);
    }
    /*
      Time Complexity : O(NxN)
      Space Complexity : O(NxN)
      Space for DP array
    */
    int tabulation(int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        for (int i = 0; i < n; i++)
            dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
    /*
     Time Complexity : O(NxN)
     Space Complexity : O(2N)
     Space for front and curr vectors.
   */
    int spaceOptimization(int n, vector<vector<int>> &triangle)
    {
        vector<int> curr(n, 0), front(n, 0);
        for (int i = 0; i < n; i++)
            front[i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }
        return front[0];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // return recursion(0,0,n,traingle)

        // return memoziation(0,0,n,traingle,dp)

        // return tabulation(n,traingle,dp)

        return spaceOptimization(n, triangle);
    }
};