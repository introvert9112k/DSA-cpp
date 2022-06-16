 #include <bits/stdc++.h>
using namespace std;

void dfsofGraph(int vertex, vector<bool> &visited, vector<int> graph[], vector<int> &dfs)
{
    // Take action on vertex after entering the vertex
    dfs.push_back(vertex);
    visited[vertex] = true;
    for (int &node : graph[vertex])
    {
        // Take action on the child before entering the child node
        if (!visited[node])
            dfsofGraph(node, visited, graph, dfs);
        // Take action on the after exiting the child node
    }
    // take action on the verterx before exiting the vertex
    // Time complexity -----O(V+E)
    // recursive calls are called on every vertex so O(v) and for each vertex call we are iterating over all it's childs. IN total for
    // loop will run for multiple of edges times i.e O(k*E)
    // so overall time complexity is O(V+E)
    // Space Complexity O(N+E) + O(N) + O(N) for adjancey list,dfs vector,visited array
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1]; // 1based indexing
    vector<bool> visited(n + 1);
    vector<int> dfs;
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
            dfsofGraph(i, visited, graph, dfs);
    } 
    cout << "dfs traversal of the graph is : " << endl;
    for (auto &val : dfs)
        cout << val << " ";
    return 0;
} 