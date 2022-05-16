// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> bfsOfGraph(int n, vector<int> graph[])
{
    vector<int> bfs;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto &it : graph[i])
                {
                    if (visited[it] == false)
                    {
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
    }
    return bfs;
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