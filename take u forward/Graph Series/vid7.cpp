// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// DFS

void dfs(vector<bool> &visited, int vtx, vector<int> graph[], vector<int> &ans)
{
    visited[vtx] = true;
    ans.push_back(vtx);

    for (auto &child : graph[vtx])
        if (!visited[child])
            dfs(visited, child, graph, ans);
}

vector<int> DFSOfGraph(int n, vector<int> graph[])
{
    vector<int> ans;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(visited, i, graph, ans);

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Adjacency List
    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> ans = DFSOfGraph(n, graph);
    
    return 0;
}