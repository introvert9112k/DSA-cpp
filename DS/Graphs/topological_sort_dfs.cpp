#include <bits/stdc++.h>
using namespace std;
// -----------------------Topological Sort------------
// Topological sort is the linear ordering of the vertices such if we consider two vertices u and v having edge between them ,so the u appears first in the order later the v.
// There may be many topological orderings for the given graph
// Topological ordering is applicable for only Directed Acyclic Graphs

void toposort(int node, vector<int> &visited, vector<int> graph[], stack<int> &stack)
{
    visited[node] = 1;
    for (auto &adjnode : graph[node])
    {
        if (!visited[adjnode])
            toposort(adjnode, visited, graph, stack);
    }
    stack.push(node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    vector<int> visited(n), topo;
    stack<int> stack;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            toposort(i, visited, graph, stack);
    }
    while (!stack.empty())
    {
        topo.push_back(stack.top());
        stack.pop();
    }
    cout << "topological order of the graph is : " << endl;
    for (auto &val : topo)
        cout << val << " ";
    return 0;
} 