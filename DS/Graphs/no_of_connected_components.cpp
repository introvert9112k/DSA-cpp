#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> graph[N];
bool visited[N];
// problem statement
//  we should count the no of connected components in the disconnected undirected graph and store these connected components

// ----------Approach---------------
// 1.run the dfs on every vertex
// 2.If we run the dfs on vertex,then it would mark the all the vertices as visited in it's connected component
// 3.Count for no of times the dfs is running,that gives the no of connected components

void dfs(int vertex, vector<int> &component)
{

    visited[vertex] = true;
    component.push_back(vertex);
    for (int child : graph[vertex])
    {

        if (!visited[child])
            dfs(child, component);
    }
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
    int cnt = 0;                   // dfs count
    vector<vector<int>> connected; // vector of vector for stroing connected components
    vector<int> component;         // vector for finding the current connected component

    for (int i = 1; i <= n; i++)
    { // iterating over all the vertices
        if (!visited[i])
        {                      // if not visited then call for the dfs
            component.clear(); // make sure to clear the componnet vector before each dfs,because vertices of before connected component should be removed
            dfs(i, component);
            connected.push_back(component);
            cnt++;
        }
    }
    cout << "No of component are :  " << cnt << endl;
    cout << "Connected Components are : " << endl;
    for (auto vect : connected)
    {
        for (auto val : vect)
            cout << val << " ";
        cout << endl;
    }
    return 0;
} 