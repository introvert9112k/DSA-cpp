#include <bits/stdc++.h>
using namespace std;

bool searchforcycle(int vertex, vector<bool> &visited, vector<int> graph[])
{
    queue<pair<int, int>> q;
    q.push({vertex, -1});
    visited[vertex] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        for (auto adjnode : graph[node])
        {
            if (!visited[adjnode])
            {
                visited[adjnode] = true;
                q.push({adjnode, node});
            }
            else if (parent != adjnode)
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    bool flag = true;
    cin >> n >> m;
    vector<int> graph[n + 1];
    vector<bool> visited(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (searchforcycle(i, visited, graph))
            {
                cout << "cycle detected" << endl;
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "There is no cycle" << endl;

    return 0;
}
