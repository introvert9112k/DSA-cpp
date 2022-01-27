// Prims Minimum spanning tree Algorthim
// Minimum spanning tree is the tree obtained by converting the undirected weighted graph into tree with minimum cost
// There may be multiple minimum spanning trees possible
// MST are not possible for graphs with more than one components
// Mst are possible for the single component undirected graphs.

// prims Algorthim Intuition
// it is an greedy Algorthim.
// First we would take the source node into mst. Later we check for all the adjacent nodes of it with minimum edge cost and we take this node into mst.
// Now the mst has two nodes now we will choose a such edge such that it has minimum cost among all the edges of the nodes present in mst.
// That mean, if we have two nodes in mst then we will iterate about all the adjnodes of two nodes and find minimum among them and take into mst
// Now mst has three nodes, now we will find all the adjnodes of the nodes in mst and take the adjnode with minimum edge value and add it to mst
// This process continues until the mst contains all the vertices
#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int _n, _m;
    int mincost = 0;

public:
    Graph(int n, int m)
    {
        _n = n;
        _m = m;
    }
    void primsbruteforce()
    {
        // Taking edges as input
        vector<pair<int, int>> graph[_n];
        // Building the graph
        for (int i = 0; i < _m; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            graph[v1].push_back({v2, w});
            graph[v2].push_back({v1, w});
        }
        // Take three vectors key,mst,parent
        // key is for keep tracking the adjnode with minimum value
        // mst is to keep track of the nodes present in mst
        // parent is keeping track of the parents of the nodes, so that we can build the mst from these child and parent nodes

        // Intially all the nodes have cost IN_MAX
        vector<int> key(_n, INT_MAX);
        // Intially there is no parents
        vector<int> parent(_n, -1);
        // Intially there is no node in mst
        vector<bool> mst(_n, false);
        // make the source node i.e 0 value to be zero
        key[0] = 0;
        // there is no parent to source node i.e parent[0] = -1
        parent[0] = -1;

        // We require n-1 edges so iterate until n-1 times, In each iteration we are finding new node i.e making an edge
        for (int i = 1; i < _n; i++)
        {
            // First find the node with minimum value among the key array.
            // The node should not be present in the mst,because the node is already taken,
            int min_val = INT_MAX, node;
            // Iterating throughout the key array
            for (int i = 0; i < _n; i++)
            {
                if (mst[i] == false and key[i] < min_val)
                {
                    min_val = key[i];
                    node = i;
                }
            }
            // This the node to be taken into mst
            // so make mst of the node to true
            mst[node] = true;
            mincost += min_val;
            // Now iterate over the adjacent nodes of the node,and check whether the cost of the adjnode is greater than the cost of edge between node and adjnode. If yes then update the edge cost.
            // In the later traverses we may find the chepaest edge to reach this adjnode again.
            for (auto &adjnode : graph[node])
            {
                int node2 = adjnode.first;
                int weight = adjnode.second;
                // check whether is not in mst, and existing edge cost is greater than the edge cost b/w node and adjnode ?
                // If yes update the edge cost and mark parent of adjnode to be the current node
                if (mst[node2] == false and weight < key[node2])
                {
                    key[node2] = weight;
                    parent[node2] = node;
                }
            }
        }
        int mi = INT_MAX;
        for (int i = 0; i < _n; i++)
            if (mst[i] == false and key[i] < mi)
                mi = key[i];
        mincost += mi;
        for (int i = 0; i < _n; i++)
            cout << parent[i] << " " << i << endl;
        cout << "minimum cost of the spanning tree is : " << mincost << endl;

        // Time complexity ------ More than O(N^2)
    }
    void primsefficent()
    {
        vector<pair<int, int>> graph[_n];
        for (int i = 0; i < _m; i++)
        {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            graph[v1].push_back({v2, w});
            graph[v2].push_back({v1, w});
        }
        vector<int> key(_n, INT_MAX);
        vector<int> parent(_n, -1);
        vector<bool> mst(_n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0}); 
        for (int i = 1; i < _n; i++)
        {
            int node = pq.top().second;
            pq.pop();
            mst[node] = true;
            for (auto &adjnode : graph[node])
            {
                int node2 = adjnode.first;
                int weight = adjnode.second;
                if (mst[node2] == false and weight < key[node2])
                {
                    key[node2] = weight;
                    parent[node2] = node;
                    pq.push({weight, node2});
                }
            }
        }
        for (int i = 0; i < _n; i++)
            cout << parent[i] << " " << i << endl;
        cout << "minimum cost of the spanning tree is  : " << mincost << endl;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    g.primsefficent();
} 