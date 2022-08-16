#include <bits/stdc++.h>
using namespace std;
// problem statement
/*This is an slight modification in the original Frog Jump Problem,Here frog can jump upto k steps
That mean frog can take jump of 1 to k steps.*/

// Recursion Code
int minimumEnergy(int ind, vector<int> &heights, int k)
{
    if (ind == 0)
        return 0;
    int minSteps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind - i >= 0)
        {
            int jump = minimumEnergy(ind - i, heights, k) + abs(heights[ind] - heights[ind - i]);
            minSteps = min(jump, minSteps);
        }
    }
    return minSteps;
}

/* Memoziation
Time Complexity : O(n*k)
Space Complexity : O(2*N)
N for dp array and N for recursion stack space
*/
int minimumEnergy(int ind, vector<int> &heights, int k, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind == 0)
        return 0;
    int minSteps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind - i >= 0)
        {
            int jump = minimumEnergy(ind - i, heights, k) + abs(heights[ind] - heights[ind - i]);
            minSteps = min(jump, minSteps);
        }
    }
    return dp[ind] = minSteps;
}

/* Tabulation
 Time Complexity : O(N*K)
 Space Complexity : O(N) for the DP Array
*/
int MinEnergy(int n, vector<int> &heights, int k, vector<int> &dp)
{
    dp[0] = 0;
    int minSteps, jump;
    for (int i = 1; i < n; i++)
    {
        minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}
int main()

{
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    cout << "Minimum Energy required to reach nth Step is ";
    vector<int> dp(n, -1);
    // For recursion
    //  cout << minimumEnergy(n - 1, heights, k) << endl;
    // For Memoziation
    // cout << minimumEnergy(n - 1, heights, k, dp) << endl;
    // For Tabulation
    cout << MinEnergy(n - 1, heights, k, dp) << endl;

    return 0;
} 