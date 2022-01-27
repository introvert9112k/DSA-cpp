#include <bits/stdc++.h>
using namespace std;

bool searchforcycle(int vertex, vector<int> &visited, vector<int> &dfsvisited, vector<int> graph[])
{
    visited[vertex] = 1;
    dfsvisited[vertex] = 1;
    for (auto &adjnode : graph[vertex])
    {
        if (!visited[adjnode])
        {
            if (searchforcycle(adjnode, visited, dfsvisited, graph))
                return true;
        }
        else if (visited[adjnode] == dfsvisited[adjnode])
            return true;
    }
    dfsvisited[vertex] = 0;
    return false;
}
bool iscycle(int n, vector<int> graph[])
{
    vector<int> visited(n), dfsvisited(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (searchforcycle(i, visited, dfsvisited, graph))
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
} 