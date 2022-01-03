#include <bits/stdc++.h>
using namespace std;

class disjoint
{
private:
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    disjoint(int _n)
    {
        n = _n;
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
    bool checkcomponent(int node1, int node2)
    {
        return findparent(node1) == findparent(node2);
    }
}; 

int main()
{
    int n;
    cout << "enter the no of nodes" << endl;
    cin >> n;
    disjoint dj(n);
    // given two nodes we can make the union of these two nodes
    // for the given node we can find the parent
    // For the given two nodes we can check whether they belong to same component or not .
    // if the parent of two node is same then they belong to same component else not.
}