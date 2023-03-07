/*
1. Bellman Ford Algorthim is used to find the shortest distance from the source node to the all other nodes in the Directed Graph.

2. It is not used for Undirected graph,it works when there is negative edges tooo.

3. In case of the undirected graph we should convert the graph into direct graph for the application of the Bellaman Ford Algorithm.

4. In case of Negative cycle it gives wrong result,we should check whether there is negative cycle or not

5. In case of negative cycle shortest distance is not possible it can be used to find the negative cycles in the graph

6. Time complexity is  O((N-1)xE) which is not preferrable when compared to dijkstra's algorthim,but it helps in finding whether there is negative cycle or not.

7.In Bellaman For Edges can be any order.

8.In Bellaman Ford the We iterate each edge for N-1 times and relax the edges. 

9.Why N-1 times because shortest distance from the source node to any ohter node can have atmost N-1 edges. 

10.In case of negative cycle, When we do the nth iteration the relaxtion still be done but required are at max N-1 iterations only, so we can confirm that there is negative cycle in the graph.
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int node1;
    int node2;
    int weight;
    Node(int _node1, int _node2, int _weight)
    {
        node1 = _node1;
        node2 = _node2;
        weight = _weight;
    }
};
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
    void bellmanford() 
    {
        vector<Node> edges;
        vector<int> distance(_n, INT_MAX);
        distance[_source] = 0;
        for (int i = 0; i < _m; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            edges.push_back(Node(v1, v2, w));
        }
        for (int i = 1; i < _n; i++)
        {
            for (auto &edge : edges)
            {
                if ((distance[edge.node1] + edge.weight) < distance[edge.node2])
                    distance[edge.node2] = distance[edge.node1] + edge.weight;
            }
        }
        bool flag = false;
        /*checking for negative cycle in graph,if we find negative then the shortest distance is not possible*/
        for (auto &edge : edges)
            if (distance[edge.node1] + edge.weight < distance[edge.node2])
            {
                cout << "Negative cycle Detected" << endl;
                flag = true;
                break;
            }
        /*if negative cycle not found print the shortest distance*/
        if (!flag)
        {
            for (int i = 0; i < _n; i++)
                cout << i << " " << distance[i] << endl;
        }
    }
}; 

int main()
{
    int n, m, source;
    cin >> n >> m >> source;
    Graph g(n, m, source);
    g.bellmanford();
} 