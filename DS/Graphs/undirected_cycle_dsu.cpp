// given an undirected graph detect the presence of cycle in graph using dsu
#include <bits/stdc++.h>
using namespace std;

class disjoint
{
public:
    vector<int> rank;
    vector<int> parent;
    disjoint(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i), rank.push_back(0);
    }
    int findparent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findparent(parent[node]);
    }

    void make_union(int node1, int node2)
    {
        int p1 = findparent(node1), p2 = findparent(node2);
        if (rank[p1] > rank[p2])
            parent[p2] = p1;
        else if (rank[p2] > rank[p1])
            parent[p1] = p2;
        else
            parent[p2] = p1, rank[p1]++;
    }
    bool checkcomponents(int node1, int node2)
    {
        return findparent(node1) == findparent(node2);
    }
};
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    cout << "Enter 0 based index nodes edges" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    disjoint dj(n);
    for (auto &edge : edges)
    {
        if (!dj.checkcomponents(edge.first, edge.second))
            dj.make_union(edge.first, edge.second);

        else
        {
            cout << "cycle detected" << endl;
            return 0;
        }
    }
    cout << " Cycle not detected " << endl;
    return 0;
}