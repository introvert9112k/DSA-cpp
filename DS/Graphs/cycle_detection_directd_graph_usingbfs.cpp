#include <bits/stdc++.h>
using namespace std;

bool serachforcycle(int n, vector<int> graph[])
{
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
    {
        for (auto &adjnode : graph[i])
            indegree[adjnode]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!indegree[i])
            q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto &adjnode : graph[node])
        {
            indegree[adjnode]--;
            if (!indegree[adjnode])
            {
                q.push(adjnode);
            }
        }
    }
    return cnt == n;
}
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
    serachforcycle(n, graph) ? (cout << "cycle not detected") : (cout << "cycle detected");
} 