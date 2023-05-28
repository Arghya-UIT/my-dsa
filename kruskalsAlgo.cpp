#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class and function definitions here...
class DisjointSet
{
    vector<int> size, rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        // size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int FindUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        else
        {
            return parent[node] = FindUParent(parent[node]);
        }
    }
    void UnionByRank(int u, int v)
    {
        int ulp_u = FindUParent(u);
        int ulp_v = FindUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
    // void UnionBySize(int u, int v)
    // {
    //     int up_u = FindUParent(u);
    //     int up_v = FindUParent(v);

    //     if (up_u == up_v)
    //         return;

    //     if (size[up_u] < size[up_v])
    //     {
    //         parent[up_u] = up_v;
    //         size[up_v] += size[up_u];
    //     }
    //     else
    //     {
    //         parent[up_v] = up_u;
    //         size[up_u] += size[up_v];
    //     }
    // }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int ,int>>>edge;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=it[0];
                int v=i;
                int w=it[1];
                edge.push_back({w,{u,v}});
                
            }
        }
        DisjointSet ds(V);
        sort(edge.begin(),edge.end());
        int tot=0;
        for(auto it:edge){
            int w=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.FindUParent(u)!=ds.FindUParent(v)){
                tot+=w;
                ds.UnionByRank(u,v);
            }
        }
        return tot;
    }
};

int main() {
    int V = 4;  // Number of vertices

    // Creating the adjacency list representation of the graph
    vector<vector<int>> adj[V];

    // Adding edges to the graph
    adj[0].push_back({1, 1, 10});
    adj[0].push_back({2, 2, 6});
    adj[0].push_back({3, 3, 5});
    adj[1].push_back({3, 1, 15});
    adj[2].push_back({3, 2, 4});

    Solution obj;
    int totalWeight = obj.spanningTree(V, adj);

    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;

    return 0;
}
