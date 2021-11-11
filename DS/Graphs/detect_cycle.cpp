// problem statement
// given an undirected graph we should say whether cycle is found in graph or not
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> graph[N];
bool visited[N];

void dfs(int vertex)
{

    visited[vertex] = true;
    for (int child : graph[vertex])
    {

        if (!visited[child])
            dfs(child);
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
    dfs(1);
    return 0;
}