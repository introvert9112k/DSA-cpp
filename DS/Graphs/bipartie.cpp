#include <bits/stdc++.h>
using namespace std;

bool isbipartite(int n, vector<int> graph[])
{
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto &adjnode : graph[node])
                {
                    if (color[adjnode] == -1)
                    {
                        color[adjnode] = 1 - color[node];
                        q.push(adjnode);
                    }
                    else if (color[adjnode] == color[node])
                        return false;
                }
            }
        }
    }
    return true;
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
    isbipartite(n, graph) ? (cout << "graph is bipartite";) : (cout << "graph is not bipartite");
} 