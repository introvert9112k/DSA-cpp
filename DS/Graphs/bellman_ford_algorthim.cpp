// bellman Ford Algorthim is used to find the shortest distance from the source node to the all other nodes in the Directed Graph.
// it is not used for Undirected graph,it works when there is negative edges tooo
// In case of Negative cycle it gives wrong result,we should check whether there is negative cycle or not
// In case of negative cycle shortest distance is not possible
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
        for (auto &edge : edges)
            if (distance[edge.node1] + edge.weight < distance[edge.node2])
            {
                cout << "Negative cycle Detected" << endl;
                flag = true;
                break;
            }
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