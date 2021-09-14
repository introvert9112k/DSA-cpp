// problem statement
// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/goldmine-official/ojquestion

#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
int solve(vector<vector<int>> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size()));
    for (int j = arr[0].size() - 1; j >= 0; j--)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (j == arr[0].size() - 1 and i == 0)
                dp[i][j] = arr[i][j];
            else if (j == arr[0].size() - 1)
                dp[i][j] = arr[i][j] + dp[i - 1][j];
            else if (i == 0)
                dp[i][j] = arr[i][j] + max(dp[i + 1][j + 1], dp[i][j + 1]);
            else if (i == arr.size() - 1)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            else
                dp[i][j] = arr[i][j] + max({dp[i][j + 1], dp[i - 1][j + 1], dp[i + 1][j + 1]});
        }
    }
    int mx = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
        mx = max(mx, dp[i][0]);

    print(dp);
    return mx;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            arr[i].push_back(x);
        }
    }
    cout << solve(arr) << endl;
    return 0;
} 