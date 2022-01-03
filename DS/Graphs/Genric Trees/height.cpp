#include <bits/stdc++.h>
using namespace std;

int height(int node, vector<int> graph[])
{
    if (graph[node].size() == 0)
        return 0;
    vector<int> v;
    for (auto &adjnode : graph[node])
        v.push_back(height(adjnode, graph));
    return *max_element(v.begin(), v.end()) + 1;
} 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    int h = height(0, graph);
    cout << "height of the tree is : " << h << endl;
} 