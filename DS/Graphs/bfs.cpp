// Breadth First Search
// Bfs is the traversing the adjacent nodes at first.After that move to next nodes.
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsofGraph(int n, vector<int> graph[])
{
    // vector for storing bfs of the graph
    vector<int> bfs;
    // visited array to keep track of visited vertices/nodes
    vector<bool> visited(n + 1,false);
    for (int i = 1; i <=n; i++) // traversing the every vertex,this make sures to cover all the components in disconnected graph
    {
        if (!visited[i]) // we only traverse vertices that is unvisited,so checking whether the vertex is visited or not
        {
            queue<int> q;      // for every component we take a queue and traverse through all the vertices in that component
            q.push(i);         // push the starting vertex of the component into the queue.
            visited[i] = true; // mark the current vertex as visited
            while (!q.empty()) // iterating until the queue is not empty
            {
                int vertex = q.front();            // take the top vertex in the queue
                q.pop();                         // pop it from the queue
                bfs.push_back(vertex);           // push into the bfs vector
                for (auto &node : graph[vertex]) // iterating through the vertices connected to the current vertex
                {
                    if (!visited[node]) // if the adjacent vertex is not visted then mark it as visited and push into the queue.
                    {
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
        }
    }
    return bfs;
} 
// --------------Compplexities-------------
// T --------- O(N+2*E) N for traversing the all vertices, E for traversing all the edges in graph overall
// Space ---------- O(N+2*E) + O(N) + O(N) for Adjacency list,visited array,bfs vector

// -----------Connected Components------------
// No of connected components is equal to the numbers of times the if loop is excuted

int main()
{

    int n, m;
    cin >> n >> m;
    // 1 based indexing
    vector<int> graph[n + 1];
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    vector<int> bfs = bfsofGraph(n, graph);
    cout << "bfs travel of the graph is : " << endl;
    for (auto &vertex : bfs)
        cout << vertex << " ";

    return 0;
} 