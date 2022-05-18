// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<int> graph[], vector<bool> &visited, vector<int> &t_insert, vector<int> &min_time, vector<vector<int>> &ans, int vtx, int parent, int &timer)
{
    visited[vtx] = true;
    t_insert[vtx] = timer;
    min_time[vtx] = timer;
    timer++;

    for (auto &child : graph[vtx])
    {
        if (child == parent)
            continue;
        if (!visited[child])
        {
            dfs(graph, visited, t_insert, min_time, ans, child, vtx, timer);
            min_time[vtx] = min(min_time[vtx], min_time[child]);
            if (min_time[child] > t_insert[vtx])
                ans.push_back({child, vtx});
        }
        else
            min_time[vtx] = min(min_time[vtx], t_insert[child]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> t_insert(n + 1, -1);
    vector<int> min_time(n + 1, -1);

    vector<vector<int>> ans;

    int timer = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(graph, visited, t_insert, min_time, ans, i, i, timer);
    }

    return 0;
}