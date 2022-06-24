#include <bits/stdc++.h>
using namespace std;

// source : strivers playlist
// Time Complexity : O(4^(N^2))
// Space Complexity : O(N)
class Solution
{
public:
    typedef vector<vector<int>> vvi;
    /*checking all the possiblites*/
    void findpaths(int i, int j, int n, vvi &matrix, vvi &visited, string &s, vector<string> &ans)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            return;
        }
        // down
        if (i + 1 < n && !visited[i + 1][j] && matrix[i + 1][j])
        {
            s.push_back('D');
            visited[i + 1][j] = 1;
            findpaths(i + 1, j, n, matrix, visited, s, ans);
            visited[i + 1][j] = 0;
            s.pop_back();
        }
        // left
        if (j - 1 >= 0 && !visited[i][j - 1] && matrix[i][j - 1])
        {
            s.push_back('L');
            visited[i][j - 1] = 1;
            findpaths(i, j - 1, n, matrix, visited, s, ans);
            visited[i][j - 1] = 0;
            s.pop_back();
        }
        // Right
        if (j + 1 < n && !visited[i][j + 1] && matrix[i][j + 1])
        {
            s.push_back('R');
            visited[i][j + 1] = 1;
            findpaths(i, j + 1, n, matrix, visited, s, ans);
            visited[i][j + 1] = 0;
            s.pop_back();
        }
        // up
        if (i - 1 >= 0 && !visited[i - 1][j] && matrix[i - 1][j])
        {
            s.push_back('U');
            visited[i - 1][j] = 1;
            findpaths(i - 1, j, n, matrix, visited, s, ans);
            visited[i - 1][j] = 0;
            s.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string s = "";
        vector<vector<int>> visited(n, vector<int>(n, 0)); /*to know which cells are visited in current path*/
        if (m[0][0])                                       /*If first cell is blocked, there is no path at all*/
        {
            visited[0][0] = 1;
            findpaths(0, 0, n, m, visited, s, ans);
        }
        return ans;
    }
};
int main()
{
    return 0;
} 