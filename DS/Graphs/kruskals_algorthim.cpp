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

class kruskals
{
private:
    int n, m;
    vector<int> parent;
    vector<int> rank;

public:
    kruskals(int _n, int _m)
    {
        n = _n;
        m = _m;
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int findparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }
    void unions(int node1, int node2)
    {
        int p1 = findparent(node1);
        int p2 = findparent(node2);
        if (rank[p1] > rank[p2])
            parent[p2] = p1;
        else if (rank[p2] > rank[p1])
            parent[p1] = p2;
        else
        {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
    bool components(int node1, int node2)
    {
        return findparent(node1) == findparent(node2);
    }
    static bool cmp(Node n1, Node n2)
    {
        return n1.weight < n2.weight;
    }
    void kruskalsalgorthim()
    {
        vector<Node> edges;
        vector<pair<int, int>> mst;
        int mincost = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(Node(u, v, w));
        } 
        sort(edges.begin(), edges.end(), cmp);
        for (auto &edge : edges)
        {
            if (!components(edge.node1, edge.node2))
            {
                mincost += edge.weight;
                mst.push_back({edge.node1, edge.node2});
                unions(edge.node1, edge.node2);
            }
        }
        cout << "minimum cost of the minimum spanning tree is : " << mincost << endl;
        for (auto &edge : mst)
            cout << edge.first << " " << edge.second << endl;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    kruskals k(n, m);
    k.kruskalsalgorthim();
} 