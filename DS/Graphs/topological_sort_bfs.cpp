#include <bits/stdc++.h>
using namespace std;

vector<int> toposort(int n, vector<int> graph[])
{
    vector<int> indegree(n), topo;
    for (int i = 0; i < n; i++)
    {
        for (auto &adjnode : graph[i])
            indegree[adjnode]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto &adjnode : graph[node])
        {
            indegree[adjnode]--;
            if (indegree[adjnode] == 0)
                q.push(adjnode);
        }
    }
    return topo;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n], topo;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
} 