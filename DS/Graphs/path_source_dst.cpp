// problem statement
// given an undirected graph,and given two vertices find whether there exists path between two vertices or not
// Approach
// Run the either bfs or dfs from the source node and check whether we encounter the destination node in the traversal or not
#include <bits/stdc++.h>
using namespace std;

bool checkpathbfs(vector<int> graph[], int src, int dst, vector<int> &visited)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &adjnode : graph[node])
        {
            if (adjnode == dst)
                return true;
            if (visited[adjnode] == false)
            {
                visited[adjnode] = true;
                q.push(adjnode);
            }
        }
    }
    return false;
}

bool checkpathdfs(vector<int> graph[], int src, int dst, vector<int> &visited)
{
    visited[src] = true;
    if (src == dst)
        return true;
    for (auto &adjnode : graph[src])
    {
        if (visited[adjnode] == false)
        {
            if (checkpathdfs(graph, adjnode, dst, visited))
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
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int src, dst;
    cin >> src >> dst;
    vector<int> visited(n, false);
    checkpathbfs(graph, src, dst, visited);
    // checkpathdfs(graph, src, dst, visited);
    return 0;
}