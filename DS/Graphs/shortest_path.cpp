// problem statement
// given a source node,find the shortest distance from the soruce node to the every other node in the graph
#include <bits/stdc++.h>
using namespace std;
// strivers approach
void shortestdistance(int source, vector<int> graph[], vector<int> &distance)
{
    queue<int> q;
    q.push(source);
    distance[source] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &adjnode : graph[node])
        {
            if (distance[node] + 1 < distance[adjnode])
            {
                distacne[adjnode] = distance[node] + 1;
                q.push(adjnode);
            }
        }
    }
}
// easiest approach
void shortestdistance(int n, int source, vector<int> graph[], vector<int> &distance)
{
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    distance[source] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &adjnode : graph[node])
        {
            if (!visited[adjnode])
            {
                distance[adjnode] = distance[node] + 1;
                visited[adjnode] = 1;
                q.push(adjnode);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n], distance(n, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int source;
    cin >> source;
    shortestdistance(n, source, graph, distance);
    // shortestdistance(source, graph, distance);
    cout << "the shortest distances from the source to all nodes is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}