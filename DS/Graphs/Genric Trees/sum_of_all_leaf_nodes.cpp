#include <bits/stdc++.h>
using namespace std;

void sumofallleafs(int node, vector<int> graph[], int &sum)
{
    if (graph[node].size() == 0)
        sum += node;
    for (auto &adjnode : graph[node])
        sumofallleafs(adjnode, graph, sum);
}
void sumofallleafs2(int node, vector<int> graph[], int &sum)
{
    queue<int> q;
    q.push(node);
    while (not q.empty())
    {
        int node = q.front();
        q.pop();
        if (graph[node].size() == 0)
            sum += node;
        for (auto &adjnode : graph[node])
            q.push(adjnode);
    }
} 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    int sum = 0;
    sumofallleafs2(0, graph, sum);
    cout << "sum of all the leaf nodes is : " << sum << endl;
} 