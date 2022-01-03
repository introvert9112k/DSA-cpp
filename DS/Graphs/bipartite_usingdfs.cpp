#include <bits/stdc++.h>
using namespace std;

bool searchforcycle(int vertex, vector<int> &color, vector<int> graph[])
{
    if (color[i] == -1)
        color[i] = 1;
    for (auto &adjnode : graph[vertex])
    {
        if (color[adjnode] == -1)
        {
            color[adjnode] = 1 - color[vertex];
            if (!searchforcycle(adjnode, color, graph))
                return false;
        }
        else if (color[adjnode] == color[vertex])
            return false;
    }
    return true;
} 

bool iscycle(int n, vector<int> graph[])
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (searchforcycle(i, color, graph))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
}