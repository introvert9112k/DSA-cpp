// performing DFS on the graph in matrix representation
#include <bits/stdc++.h>
using namespace std;
void DFS(int node, int v, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < v; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            visited[i] = true;
            DFS(i, v, graph, visited);
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
    DFS(0, v, graph, visited);
    return 0;
} 