// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Shortest Path in Undirected Graph with Unit Weights

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src = 0;

    vector<int> distances(n, 1e8);
    queue<int> q;
    q.push(src);
    distances[src] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto &child : adj[front])
        {
            if (distances[child] > distances[front] + 1)
            {
                distances[child] = distances[front] + 1;
                q.push(child);
            }
        }
    }

    return 0;
}