// problem statement
// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs or 3 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

#include <bits/stdc++.h>
using namespace std;
// general recursive appraoch/
int recursive(int n, string path)
{
    if (n == 0)
    {
        cout << path << endl;
        return 1;
    }
    if (n < 0)
        return 0;
    int n1 = recursive(n - 1, path + "1");
    int n2 = recursive(n - 2, path + "2");
    int n3 = recursive(n - 3, path + "3");
    return n1 + n2 + n3;
}
// using memoziation
int memoziation(int n, string path, int *qb)
{
    if (n == 0)
    {
        cout << path << endl;
        return 1;
    }
    if (n < 0)
        return 0;
    if (qb[n] != 0)
        return qb[n];
    int n1 = recursive(n - 1, path + "1");
    int n2 = recursive(n - 2, path + "2");
    int n3 = recursive(n - 3, path + "3");
    qb[n] = n1 + n2 + n3;
    return n1 + n2 + n3;
}
// using tabulaztion
int tabulization(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 or i == 1)
            dp[i] = 1;
        else if (i == 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else

            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}
int main()

{
    int n;
    cin >> n;
    int qb[n + 1] = {0};
    cout << "the ways we can reach the stairs is : " << endl;
    // cout << recursive(n, "") << endl;
    // cout << memoziation(n, "",qb) << endl;
    cout << tabulization(n) << endl;

    return 0;
}