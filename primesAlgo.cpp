#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(v, 0);
        pq.push({0, 0});
        int s = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int w = it.first;

            if (vis[node] != 1)
            {
                s += w;
                vis[node] = 1;
                for (auto i : adj[node])
                {
                    int adjnode = i[0];
                    int adjw = i[1];
                    if (vis[adjnode] != 1)
                    {
                        pq.push({adjw, adjnode});
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    int v = 5; // number of vertices

    // Create adjacency list representation of the graph
    vector<vector<int>> adj[v];
    adj[0].push_back({1, 2}); // edge between node 0 and node 1 with weight 2
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    Solution obj;
    int sumOfWeights = obj.spanningTree(v, adj);
    cout << "Sum of weights of the Minimum Spanning Tree: " << sumOfWeights << endl;

    return 0;
}
