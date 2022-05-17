// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bfs(vector<bool> &visited, vector<int> &ans, int vtx, vector<int> graph[])
{
    queue<int> q;
    q.push(vtx);
    visited[vtx] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto &child : graph[vtx])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(int n, vector<int> graph[])
{
    vector<int> ans;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
            bfs(visited, ans, i, graph);
    }
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

        vector<int> ans = bfsOfGraph(n, graph);

    return 0;
}