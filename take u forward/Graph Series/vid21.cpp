// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Prim's Algorithm | C++ Code Implementation
// Brute Force

vector<pair<int, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first, v = g[i].first.second, wt = g[i].second;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);
    key[0] = 0;

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        int mini = INT_MAX, node;
        for (int v = 0; v < n; v++)
            if (mini > key[v] && mst[v] == false)
                mini = key[v], node = v;

        mst[node] = true;

        for (auto &it : graph[node])
        {
            int childNode = it.first, wt = it.second;
            if (mst[childNode] == false && key[childNode] > wt)
                parent[childNode] = node, key[childNode] = wt;
        }
    }

    for (int v = 0; v < n; v++)
        if (parent[v] != -1)
            ans.push_back({v, parent[v]});
    return ans;
}