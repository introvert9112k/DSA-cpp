#include <bits/stdc++.h>
using namespace std;
/*problem Statement
Given an array of elements, find the subsequence with maximum sum such that no two elements in the subsequence are adjacent to each other in the array.

This is modification to the subsequences problem, This problem is also known as House Robber Problem.
*/
/*
Time Complexity : O(2^n)
Space Complexity : O(N)
*/
int maximumSum(int ind, vector<int> &arr)
{
    // If we reach the 0,that mean we didnot take arr[1] into our subsequence, so we can take the arr[0] into our subsequence so return arr[0]
    if (ind == 0)
        return arr[ind];
    // If ind < 0, that mean we had taken arr[1] into subsequence, we should not take arr[0] so return 0
    if (ind < 0)
        return 0;
    // f(n) gives the maximum non adjancent subsequence from index o to n
    // Taking the current number into subsequence and asking recursion to return the value of f(n-2)
    int pick = arr[ind] + maximumSum(ind - 2, arr);
    // Not Taking the current number into subsequence and asking recursion to return the value of f(n-1)
    int nonPick = 0 + maximumSum(ind - 1, arr);
    // returning the maximum among the both the subsequences.
    return max(pick, nonPick);
}

// Memoziation
/*
Time Complxity : O(n)
Space Complexity : O(2n)
*/
int maximumSum(int ind, vector<int> &arr, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind == 0)
        return arr[0];
    if (ind < 0)
        return 0;
    int pick = arr[ind] + maximumSum(ind - 2, arr, dp);
    int nonPick = 0 + maximumSum(ind - 1, arr, dp);
    return dp[ind] = max(pick, nonPick);
}
// Tabulation
/*
Time Complexity : O(N)
Space Complexity : O(N)
*/
int MaximumSum(int n, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];
    int pick, nonPick;
    for (int i = 1; i < n; i++)
    {
        pick = arr[i] + (i > 1 ? dp[i - 2] : 0);
        nonPick = 0 + dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[n - 1];
}

// Space Optmisation
/*
Time Complexity : O(N)
Space Complexity : O(1)
*/
int MaximumSum(int n, vector<int> &arr)
{
    int pick, nonPick;
    int prev2, prev = arr[0], curr;
    for (int i = 1; i < n; i++)
    {
        pick = arr[i] + (i > 1 ? prev2 : 0);
        nonPick = 0 + prev;
        curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n, -1);
    cout << "Maximum Sum of Non Adjacent Subsequence is " << endl;
    // For recursion
    cout << maximumSum(n - 1, arr) << endl;
    // For Memoziation
    cout << maximumSum(n - 1, arr, dp) << endl;
    // For Tabulation
    cout << MaximumSum(n, arr, dp) << endl;
    // For Space Optmization
    cout << MaximumSum(n, arr) << endl;
    return 0;
}
