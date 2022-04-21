#include <bits/stdc++.h>
using namespace std;
void BFS(int node, int v, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < v; i++)
        {
            if (graph[node][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}  
int main()

{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    vector<bool> visited(v, false);
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        /*Undirected graph*/
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    BFS(0, v, graph, visited);
    return 0;
}