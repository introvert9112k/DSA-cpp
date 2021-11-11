#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> graph[N];
bool visited[N];

void dfs(int vertex)
{
    // Take action on vertex after entering the vertex
    cout << vertex << endl;
    visited[vertex] = true;
    for (int child : graph[vertex])
    {
        // Take action on the child before entering the child node
        if (!visited[child])
            dfs(child);
        // Take action on the after exiting the child node
    }
    // take action on the verterx before exiting the vertex
    // Time complexity -----O(V+E)
    // recursive calls are called on every vertex so O(v) and for each vertex call we are iterating over all it's childs. IN total for
    // loop will run for multiple of edges times i.e O(k*E)
    // so overall time complexity is O(V+E)
}
int main()
{

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    return 0;
} 