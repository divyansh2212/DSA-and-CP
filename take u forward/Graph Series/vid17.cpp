// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Shortest Path in Directed Acyclic Graph (DAG)

void findTopo(vector<bool> &visited, int vtx, vector<pair<int, int>> graph[], stack<int> &topo)
{
    visited[vtx] = true;
    for (auto &child : graph[vtx])
        if (!visited[child.first])
            findTopo(visited, child.first, graph, topo);
    topo.push(vtx);
}

void shortestPath(int src, vector<pair<int, int>> graph[], int n)
{
    vector<int> dist(n, 1e9);
    vector<bool> visited(n, false);
    dist[src] = 0;

    stack<int> topo;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            findTopo(visited, i, graph, topo);

    while (!topo.empty())
    {
        int node = topo.top();
        topo.pop();

        for (auto &child : graph[node])
            if (dist[child.first] > dist[node] + child.second)
                dist[child.first] = dist[node] + child.second;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> graph[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
    }

    shortestPath(0, graph, n);

    return 0;
}