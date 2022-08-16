class Solution
{
private:
    * /
        void dfs(int node, vector<int> graph[], vector<int> &visited)
    {
        visited[node] = 1;
        for (auto &adjNode : graph[node])
        {
            if (visited[adjNode] == 0)
                dfs(adjNode, graph, visited);
        }
    }

    void bfs(int node, vector<int> graph[], vector<int> &visited)
    {
        queue<int> q;
        visited[node] = 1;
        q.push(node);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &adjNode : graph[node])
            {
                if (visited[adjNode] == 0)
                {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        vector<int> graph[v];
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int provinces = 0;
        vector<int> visited(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                provinces++;
                bfs(i, graph, visited);
            }
        }
        return provinces;
    }
}; 