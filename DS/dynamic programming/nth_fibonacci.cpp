#include <bits/stdc++.h>
using namespace std;
// Time Complexity : O(2^n)
// Space Complexity : O(n) recursive stack space

int recursion(int n)
{
    if (n <= 1)
        return n;
    return recursion(n - 1) + recursion(n - 2);
}
// in this fibonacii calculation we repeadtly calculate the value again and again,so we are uncessiarly calculating the that we already calculated,what if we can remember those values and utilize them,
// this is where is dynamic programming comes into picture, remembering the values that are already calculated is known as memoziation
// let us write effective code for this

// Time Complexity : O(n)
// In O(n) calls all the values would be calculated,next subcalls take only O(1) time
// Space Complexity : O(n) + O(n)
// Auxilary stack space and the dp vector space
int memoziation(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = memoziation(n - 1, dp) + memoziation(n - 2, dp);
}

// Time Complexity : O(n)
// Space Complexity : O(n)
// Eliminating the recursion stack space
int tabulation(int n)
{
    // here we are using tabularisation to find the nth fibonacii
    // there two ways we can approach the problem in dp,one is using the memoziation and other is the tabularization
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// just manipulating with the two pointers
// Time Complexity : O(n)
// Space Complexity : O(1)
int space_optimisation(int n)
{
    if (n <= 1)
        return n;
    int prev2 = 0, prev1 = 1, curri;
    for (int i = 2; i <= n; i++)
    {
        curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }
    return curri;
}

int main()

{
    int n;
    cin >> n;
    cout << recursion(n) << endl;
    vector<int> dp(n + 1, -1);
    cout << memoziation(n, dp) << endl;
    cout << tabulation(n) << endl;
    cout << space_optimisation(n) << endl;
    return 0;
} 