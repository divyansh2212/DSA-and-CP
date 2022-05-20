// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &dfsvis, int vtx, bool &flag)
{
    vis[vtx] = true, dfsvis[vtx] = true;

    for (auto &child : graph[vtx])
    {
        if (vis[child] && dfsvis[child])
            flag = true;
        if (!vis[child])
            dfs(graph, vis, dfsvis, child, flag);
    }
    dfsvis[vtx] = false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first, v = edges[i].second;
        graph[u].push_back(v);
    }

    bool flag = false;
    vector<bool> vis(n + 1, false), dfsvis(n + 1, false);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(graph, vis, dfsvis, i, flag);

    return flag;
}