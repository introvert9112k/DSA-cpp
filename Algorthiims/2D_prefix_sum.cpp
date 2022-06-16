#include <bits/stdc++.h>
using namespace std;

int main()

{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    vector<vector<int>> prefixsum(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefixsum[i][j] = matrix[i - 1][j - 1] + prefixsum[i - 1][j] + prefixsum[i][j - 1] - prefixsum[i - 1][j - 1];
            /*Equation for calculating the prefix sum*/
        }
    }

    int a, b, c, d;
    int x;
    cin >> x;
    while (x--)
    {
        cin >> a >> b >> c >> d;
        // Extract the sum from matrix[a][b] --> matrix[c][d]
        cout << prefixsum[c + 1][d + 1] - prefixsum[a][d + 1] - prefixsum[c + 1][b] + prefixsum[a][b] << endl;
    }
    return 0;
}