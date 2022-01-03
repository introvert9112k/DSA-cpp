#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    void toposort(int node, vector<bool> &visited, vector<int> graph[], stack<int> &topo)
    {
        visited[node] = true;
        for (pair<int, int> adjnode : graph[node])
        {
            if (!visited[adjnode.first])
                toposort(adjnode.first, visited, graph, topo);
        }
        topo.push(node);
    }

    vector<int> shortestpath(int n, int m, int source)
    {
        vector<pair<int, int>> graph[n];
        vector<bool> visited(n);
        stack<int> topo;
        for (int i = 0; i < m; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            graph[v1].push_back({v2, w});
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                toposort(i, visited, graph, topo);
        }
        vector<int> distance(n, INT_MAX);
        distance[source] = 0;
        while (!stack.empty())
        {
            int node = topo.top();
            topo.pop();
            if (distance[node] != INT_MAX)
            {
                for (pair<int, int> adjnode : graph[node])
                {

                    if (distance[node] + adjnode.second < distance[adjnode.first])
                        distance[adjnode.first] = distance[node] + adjnode.second;
                }
            }
        }
        return distance;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    int source;
    cin >> source;
    Graph g;
    vector<int> distance = g.shortestpath(n, m, source)
}