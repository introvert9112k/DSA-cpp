#include <bits/stdc++.h>
using namespace std;
// There are two methods to represent the graphs
// 1.Adjacency Matrix
// 2.Adjancency List

// -------Adjacency Matrix-------------
// if there are n vertices then make build v x v matrix
// in matrix if node i and j are connected then a[i][j] =1 else a[i][j] = 0
// In case of undirected graphs if i and j are connected then j and i also connected i.e if a[i][j]=1 then a[j][i]=1
// if the edges has weight,in undirected graphs then a[i][j] = weight and a[j][i] = weight, Always weights > 0

// -------Adjacency List----------
// if there are n vertices,we would make n lists, each representing the n vertices
// In each list we will store the corresponding chilrens of this particular vertex

// -----------Graphs Input---------------
// First two integers n and m will be given, denoting the no of vertices(n) and no of edges(m)
// then m lines follow ,each consisting info about which two vertices are conneccted

void adjacency_matrix()
{
    int n, m; // taking input of no of vertices and edges
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0)); // adjacency matrix of size nxn
    while (m--)                                              // taking input of connected vertices
    {
        int v1, v2; // taking vertex v1,and v2 as input
        cin >> v1 >> v2;
        graph[v1][v2] = 1; // connecting v1 with v2
        graph[v2][v1] = 1; // connecting v2 with v1
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    //    ---------Drawbacks---------
    //   It takes O(N^2) Space
    //   If N is larger i.e N>=10^5 we cannot build matrix.
    // usally n<=10^3

    // -----Benefits----
    // checking whether vertices i and j are connected or not takes O(1) time
}
void adjacency_list()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph1[n + 1]; // array of vectors
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1].push_back(v2);
        graph1[v2].push_back(v1);
    }
    // Space -----O(V+E)
    // usally  v =10^5, e <=10^7

    // If weights of edges are given then store the child vertex along with edge weight as pair
    // i.e given v1,v2,w  then graph[v1].push_back({v2,w}) grpah1[v2].push_back({v1,w})

    // -----Drawbacks----
    // checking whether vertices i and j are connected or not takes O(N) time
    for (int i = 1; i <= n; i++)
    {
        cout << i << "   ";
        for (auto v : graph1[i])
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    // adjacency_matrix();
    adjacency_list();
    return 0;
} 