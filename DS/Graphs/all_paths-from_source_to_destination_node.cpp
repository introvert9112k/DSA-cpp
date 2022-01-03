// problem statement
// given two nodes source and destination we should return the all the possible paths from the source to destination
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class graph
{
private:
    int n, m;
    graph(int _n, int _m)
    {
        n = _n;
        m = _m;
    }

public:
    void dfs(int node, int destination, vvi graph[], vvi &result, vi &path)
    {
        path.push_back(node);
        if (node == destination)
            result.push_back(path);
        else
        {
            for (auto &adjnode : graph[node])
                dfs(adjnode, destination, graph, result, path);
        }
        path.pop_back();
    }
    void allpaths(int source, int destination, vi graph[])
    {
        vvi result;
        vi path;
        dfs(source, destination, graph, result, path);
        cout << "All paths from " << source << " to " << destination << " are " << endl;
        for (auto &path : result)
        {
            for (auto &val : path)
                cout << val << " ";
            cout << endl;
        }
    }
}; 
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
    }
}