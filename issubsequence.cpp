#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string &S1, string &S2)
{
    int i = 0, j = 0; // pointers for string S1 and S2

    // iterating until reaching end of any one string.
    for (; i < S1.length() && j < S2.length(); j++)
        if (S1[i] == S2[j])
            i++; // incrementing i

    return (i == S1.length()); // checking conditon
}
bool isSubsequence(string &s1, string &s2, int n, int m)
{
    if (n == 0)
        return true; // we reach the end of the s1,so return true;
    if (m == 0)
        return false; // we reached end of S2,with characters remaining in s1,so return false
    if (s1[n - 1] == s2[m - 1])
        return isSubsequence(s1, s2, n - 1, m - 1); // moving ahead in both strings
    else
        return isSubsequence(s1, s2, n, m - 1); // moving ahead in only S2
}

// function to return the length of the longest common subsequence in strings S1 and S2
int isSubsequence(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + isSubsequence(s1, s2, i - 1, j - 1, dp);
    return dp[i][j] = max(isSubsequence(s1, s2, i - 1, j, dp), isSubsequence(s1, s2, i, j - 1, dp));
}

int main()

{
    string S1 = "tuf", S2 = "takeuforward";
    int n = S1.length(), m = S2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    if (isSubsequence(S1, S2, n - 1, m - 1, dp) == n) // if length of longest common subsequence is equal to S1's length then S1 is subsequence of S2,else not.
        cout << S1 << " is subsequence of " << S2 << endl;
    else
        cout << S1 << " is not subsequence of " << S2 << endl;
    return 0;
}