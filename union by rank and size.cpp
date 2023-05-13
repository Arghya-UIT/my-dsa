#include <bits/stdc++.h>
using namespace std;

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

int main()
{

    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    if (ds.FindUParent(3) == ds.FindUParent(7))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    ds.UnionByRank(3, 7);
    if (ds.FindUParent(3) == ds.FindUParent(7))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}