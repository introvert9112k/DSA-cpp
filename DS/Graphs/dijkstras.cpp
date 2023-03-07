/*
Dijkstras Algorthim

1. Dijkstras algorthim is used to find the  shortest distance from the source node to the all other nodes.

2.It is applicable to all graphs directed,undirected,directed weighted,undirected weighted,etc but the edges should not have negative weights this is only prerequiste for this algorthim

3. This is for undirected weighted graph,we can find for directed weighted graphs too

4. In Dijkstras once node is visited then the optimal distance for the node is found,so whenver we encounter the node that is already visited no need to process it because optimal distance is already found,so simply continue to other nodes

5.Visited array is optinal, Dijkstras will work fine without visited array too, using of visited array reduces the processing of nodes for which the optimal distance is already found.

*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int _n, _m, _source;

public:
    Graph(int n, int m, int source)
    {
        _n = n;
        _m = m;
        _source = source;
    }
    vector<int> shortestpath()
    {
        vector<pair<int, int>> graph[_n];
        vector<int> distance(_n, INT_MAX);
        vector<bool> visited(_n,false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < _m; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            graph[v1].push_back({v2, w});
            graph[v2].push_back({v1, w});
        }
        distance[_source] = 0;
        pq.push({0, _source});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            visited[node] = true;
            pq.pop();
            if(distance[node] < dist)
                continue;
            for (pair<int, int> adjnode : graph[node])
            {
                if (visited[adjnode.first])
                    continue;
                if (dist + adjnode.second < distance[adjnode.first])
                {
                    distance[adjnode.first] = dist + adjnode.second;
                    pq.push({distance[adjnode.first], adjnode.first});
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
    Graph g(n, m, source);
    vector<int> distance = g.shortestpath();
    cout << "the shortest path from the source node is : " << endl;
    for (int i = 0; i < n; i++)
        cout << i << " " << distance[i] << endl;
    return 0;
} 