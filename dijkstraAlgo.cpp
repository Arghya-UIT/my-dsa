#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
{
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto tp = pq.top();
        int di = tp.first;
        int no = tp.second;
        pq.pop();
        for (auto it : adj[no])
        {
            int adjno = it[0];
            int adjdi = it[1];
            if (di + adjdi < dist[adjno])
            {
                dist[adjno] = di + adjdi;
                pq.push({dist[adjno], adjno});
            }
        }
    }
    return dist;
}

int main()
{
    int v = 6; // Number of vertices
    int e = 9; // Number of edges

    vector<vector<int>> adj[v];

    // Edges and their weights
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});
    adj[3].push_back({5, 1});
    adj[4].push_back({5, 5});
    adj[5].push_back({0, 2});

    int source = 0; // Source vertex

    vector<int> distances = dijkstra(v, adj, source);

    cout << "Shortest distances from the source vertex " << source << " are:\n";
    for (int i = 0; i < v; i++)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
