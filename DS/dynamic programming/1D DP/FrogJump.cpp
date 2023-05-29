#include <bits/stdc++.h>
// Recursion code
/*
  Time Complexity : O(2^n)
  Space Complexity : O(n)
*/
int minimumEnergy(int n, vector<int> &h)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return abs(h[1] - h[0]);
    /*we got the energy required for moving from n to n-1 step and recursion findouts the minEnergy required for the moving from 0 to n-1 th step*/
    int left = minimumEnergy(n - 1, h) + abs(h[n] - h[n - 1]);
    /*we got the energy required for moving from n to n-2 step and recursion findouts the  minEnergy required for the moving from 0 to n-2 th step*/
    int right = minimumEnergy(n - 2, h) + abs(h[n] - h[n - 2]);
    /*We can move to nth step from n-1th and n-2th step, take the minimum Energy required
      step*/
    return min(left, right);
}
// Memoziation [Top to bottom ]
/*
  Time Complexity : O(N)
  Space Complexity : O(N) + O(N)
  Auxilary stack space, and dp array space
*/
int minimumEnergy(int n, vector<int> &h, vector<int> &dp)
{
    if (dp[n] != -1)
        return dp[n];
    if (n == 0)
        return 0;
    if (n == 1)
        return abs(h[1] - h[0]);
    int left = minimumEnergy(n - 1, h, dp) + abs(h[n] - h[n - 1]);
    int right = minimumEnergy(n - 2, h, dp) + abs(h[n] - h[n - 2]);
    return dp[n] = min(left, right);
}

// Tabulation [bottom to top]
/*
  Time Complexity : O(N)
  Space Complexity : O(N) for DP array
*/
int MinimumEnergy(int n, vector<int> &h)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(h[i] - h[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(h[i] - h[i - 2]);
        dp[i] = min(left, right);
    }
    // Answer will always store in last index
    return dp[n];
}
// Space Optmization
/*
  Time Complexity : O(N)
  Space Complexity : O(1)
*/
int minEnergy(int n, vector<int> &h)
{
    int secondPrevious = 0, previous = 0, current;
    for (int i = 1; i <= n; i++)
    {
        int left = previous + abs(h[i] - h[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = secondPrevious + abs(h[i] - h[i - 2]);
        current = min(left, right);
        secondPrevious = previous;
        previous = current;
    }
    return previous;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    // For recursion
    // return minimumEnergy(n-1,heights);

    // For Memoziation
    // return minimumEnergy(n-1,heights,dp);

    // For Tabulation
    // return MinimumEnergy(n-1,heights);

    // For Space Optimisation
    return minEnergy(n - 1, heights);
}  