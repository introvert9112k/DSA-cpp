/*
Dijkstra's Algorithm using set.
*/
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> set;
        set.insert({0, S});
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        while (!set.empty())
        {
            auto it = set.begin();
            int node = it->second, dist = it->first;
            set.erase(it);
            for (auto &adjNode : adj[node])
            {
                int newDist = dist + adjNode[1];
                int currDist = distance[adjNode[0]];
                int currNode = adjNode[0];
                if (newDist < currDist)
                {
                    if (currDist != INT_MAX)
                        set.erase({currDist, currNode});
                    distance[currNode] = newDist;
                    set.insert({newDist, currNode});
                }
            }
        }
        return distance;
    }
};