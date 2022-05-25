// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Topological Sort (BFS) | Kahn's Algorithm

vector<int> topologicalSort(vector<int> g[], int nodes)
{
    vector<int> inDegrees(nodes, 0);

    for (int i = 0; i < nodes; i++)
        for (auto &child : g[i])
            inDegrees[child]++;

    queue<int> q;
    for (int i = 0; i < nodes; i++)
        if (inDegrees[i] == 0)
            q.push(i);

    vector<int> ans;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);

        for (auto &child : g[top])
        {
            inDegrees[child]--;
            if (inDegrees[child] == 0)
                q.push(child);
        }
    }

    return ans;
}
