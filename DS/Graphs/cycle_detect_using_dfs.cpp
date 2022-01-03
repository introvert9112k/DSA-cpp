#include <bits/stdc++.h>
using namespace std;

void dfsofGraph(int vertex, int parent, vector<bool> &visited, vector<int> graph[])
{
    visited[vertex] = true;
    for (auto &adjnode : graph[vertex])
    {
        if (!visited[adjnode])
        {
            if (dfsofGraph(adjnode, vertex, visited, graph))
                return true;
        }
        else if (adjnode != parent)
            return true;
    }
    return false;
}
// strivers playlist
int main()
{
    int n, m;
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
            if (bfsofGraph(i, -1, visited, graph))
            {
                flag = false;
                cout << "cycle detected" << endl;
                break;
            }
        }
    }
    if (flag)
        cout << "cycle not detected" << endl;
    return 0;
}
 