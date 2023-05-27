#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
        vector<int> dist(v, 1e8);
        dist[s] = 0;
        for (int i = 0; i < v - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] + w < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int source = 0; // Source vertex

    vector<int> result = sol.bellman_ford(V, edges, source);

    cout << "Shortest distances from the source vertex " << source << " are:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << result[i] << "\n";
    }

    return 0;
}
