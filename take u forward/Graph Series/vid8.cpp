// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Cycle Detection in Undirected Graph using BFS

bool isCycle(vector<bool> &visited, int vtx, vector<int> graph[])
{
    visited[vtx] = true;
    queue<pair<int, int>> q;
    q.push({vtx, -1});

    while (!q.empty())
    {
        int node = q.front().first, parent = q.front().second;
        q.pop();

        for (auto &child : graph[node])
        {
            if (!visited[child])
            {
                q.push({child, node});
                visited[child] = true;
            }
            else if (visited[child] == true && child != parent)
                return true;
        }
    }
    return false;
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

    bool flag = false;

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (isCycle(visited, i, graph))
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Detected\n";

    return 0;
}