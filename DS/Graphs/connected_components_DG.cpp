// Given an directed graph find whether it is connected or not
#include <bits/stdc++.h>
using namespace std;

bool connected(vector<pair<int, int>> graph[], int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n, INT_MAX);
    distance[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int node = pq.front().second;
        int dist = pq.front().first;
        pq.pop();
        for (auto &adjnode : graph[node])
        {
            if (adjnode.first + dist < distance[adjnode.second])
            {
                distance[adjnode.second] = adjnode.first + dist;
                pq.push({distance[adjnode.second], adjnode.second});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << distance[i] << " ";
    cout << endl;
}
int main()

{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<pair<int, int>> graph[n];
    for (auto &edge : edges)
    {
        graph[edge.first].push_back({edge.second, 1});
    }
    connected(graph, n);
    return 0;
} 