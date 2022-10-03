// problem statement
// given a source node,find the shortest distance from the soruce node to the every other node in the graph
#include <bits/stdc++.h>
using namespace std;
// strivers approach
void shortestDistanceBFs(int source, vector<int> graph[], vector<int> &distance)
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
                distance[adjnode] = distance[node] + 1;
                q.push(adjnode);
            }
        }
    }
} 
void shortestDistanceDFs(int source, vector<int> graph[], vector<int> &distance)
{
    for (auto &adjNode : graph[source])
    {
        if ((distance[source] + 1) < distance[adjNode])
        {
            distance[adjNode] = distance[source] + 1;
            shortestDistanceDFs(adjNode, graph, distance);
        }
    }
} 
void printShortestDistances(vector<int> &distances)
{
    for (auto &dist : distances)
        cout << dist << " ";
    cout << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n], distance1(n, INT_MAX), distance2(n, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int source;
    cin >> source;
    shortestDistanceBFs(source, graph, distance1);
    printShortestDistances(distance1);
    distance2[source] = 0;
    shortestDistanceDFs(source, graph, distance2);
    printShortestDistances(distance2);
} 