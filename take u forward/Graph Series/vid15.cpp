// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Cycle Detection in Directed Graph using BFS(Kahn's Algorithm)

bool isCyclic(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegrees(n, 0);

    for (int i = 0; i < n; i++)
        for (auto &child : adj[i])
            indegrees[child]++;

    for (int i = 0; i < n; i++)
        if (indegrees[i] == 0)
            q.push(i);

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto &child : adj[node])
        {
            indegrees[child]--;
            if (indegrees[child] == 0)
                q.push(child);
        }
    }
    if (cnt == n)
        return false;
    return true;
}