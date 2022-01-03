// Prims Minimum spanning tree Algorthim
// Minimum spanning tree is the tree obtained by converting the undirected weighted graph into tree with minimum cost
// There may be multiple minimum spanning trees possible
// MST are not possible for graphs with more than one components
// Mst are possible for the single component undirected graphs.

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
        key[0] = 0;
        parent[0] = -1;
        for (int i = 1; i < _n; i++)
        {
            int min_val = INT_MAX, node;
            for (int i = 0; i < _n; i++)
            {
                if (mst[i] == false and key[i] < min_val)
                {
                    min_val = key[i];
                    node = i;
                }
            }
            mst[node] = true;
            mincost += min_val;
            for (auto &adjnode : graph[node])
            {
                int node2 = adjnode.first;
                int weight = adjnode.second;
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