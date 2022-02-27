// problem statement
// Given source and destinaion find the all possible paths from source to desitnation

#include <bits/stdc++.h>
using namespace std;

void paths(int node, int dst, vector<int> graph[], vector<bool> &visited, vector<int> &path)
{
    visited[node] = true;
    path.push_back(node);
    if (node == dst)
    {
        for (auto &val : path)
            cout << val << " ";
        cout << endl;
        // do not return from here
    }
    for (auto &adjnode : graph[node])
    {
        if (visited[adjnode] == false)
            paths(adjnode, dst, graph, visited, path);
    }
    visited[node] = false;
    path.pop_back();
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
    vector<bool> visited(n, false);
    vector<int> path;
    int src, dst;
    cout << "enter source node" << endl;
    cin >> src;
    cout << "enter the destination node" << endl;
    cin >> dst;
    paths(src, dst, graph, visited, path);
    return 0;
}