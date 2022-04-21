#include <bits/stdc++.h>
using namespace std;
// print path from source to destination .If there is multiple path print any path
bool FindPath(int src, int dst, vector<int> graph[], vector<bool> &visited, vector<int> &path)
{
    visited[src] = true;
    path.push_back(src);
    if (src == dst)
        return true;
    for (auto &adjnode : graph[src])
    {
        if (visited[adjnode] == false)
        {
            if (FindPath(adjnode, dst, graph, visited, path))
                return true;
        }
    }
    path.pop_back();
    return false;
} 
// Path between two nodes using bfs
/*Important*/
void FindPath2(int src, int dst, vector<int> graph[], vector<bool> &visited, vector<int> &path)
{
    queue<int> q;
    q.push(src);
    unordered_map<int, int> parent;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &adjnode : graph[node])
        {
            if (visited[adjnode] == false)
            {
                parent[adjnode] = node;
                visited[adjnode] = true;
                q.push(adjnode);
            }
        }
    }
    while (dst != src)
    {
        path.push_back(dst);
        dst = parent[dst];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    vector<bool> visited(v, false);
    int src, dst;
    cin >> src >> dst;
    vector<int> path;
    FindPath2(src, dst, graph, visited, path);
    for (auto &node : path)
        cout << node << " ";
    cout << endl;
    return 0;
} 