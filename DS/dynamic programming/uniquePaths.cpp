class Solution
{
private:
    /*Recursion :
     Time Complexity: O(2^(m*n))
     Because for each cell there are two possiblites either go down or right.
     Space Complexity : O(m+n-2)
     Recursion stak space is equal to path length i.e m - 1 + n -1
    */
    int countPaths1(int row, int col)
    {
        if (row == 0 && col == 0)
            return 1;
        if (row < 0 || col < 0)
            return 0;
        return countPaths1(row, col - 1) + countPaths1(row - 1, col);
    }
    /*
      Memoziation
      Time Complexity : O(m*n)
      Space Complexity : O(m*n) + O(m+n-2)
      Recursion stak space is equal to path length i.e m - 1 + n -1
      Recursion stack space and the dp array space.
    */
    int countPaths2(int row, int col, vector<vector<int>> &dp)
    {
        if (dp[row][col] != -1)
            return dp[row][col];
        if (row == 0 && col == 0)
            return 1;
        if (row < 0 || col < 0)
            return 0;
        return dp[row][col] = countPaths2(row, col - 1, dp) + countPaths2(row - 1, col, dp);
    }
    /*
     Tabulation
     Time Complexity : O(m*n)
     Space Complexity : O(m*n)
     Dp array space.
   */
    int countPaths3(int m, int n, vector<vector<int>> &dp)
    {
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int left = j > 0 ? dp[i][j - 1] : 0;
                int up = i > 0 ? dp[i - 1][j] : 0;
                dp[i][j] = up + left;
            }
        }
        return dp[m][n];
    }
    /*
    Space Optimization
    Time Complexity : O(m*n)
    Space Complexity : O(2*n)
    Space for the two arrays prevDP and currDP
    */
    int countPaths4(int m, int n)
    {
        vector<int> prevDP(n + 1, 0), currDP(n + 1, 0);
        currDP[0] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 && j == 0)
                {
                    prevDP = currDP;
                    continue;
                }
                int left = j > 0 ? currDP[j - 1] : 0;
                int up = i > 0 ? prevDP[j] : 0;
                currDP[j] = up + left;
                prevDP = currDP;
            }
        }
        return currDP[n];
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths4(m - 1, n - 1);
    }
};