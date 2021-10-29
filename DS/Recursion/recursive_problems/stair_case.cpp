#include <bits/stdc++.h>
using namespace std;

int countways(int n, unordered_map<int, int> &map)
{
    if (n == 1 or n == 2)
        return n;
    if (map[n])
        return map[n];
    int l = countways(n - 1, map);
    int r = countways(n - 2, map);
    map[n] = l + r;
    return l + r;
}

int countways1(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int main()

{
    int n;
    cin >> n;
    unordered_map<int, int> map;
    // cout << countways(n, map) << endl;
    cout << countways1(n) << endl;

    return 0;
}