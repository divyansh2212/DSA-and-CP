// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isCycle(vector<bool> &visited, int vtx, vector<int> graph[], int parent)
{
    bool flag = false;
    visited[vtx] = true;
    for (auto &child : graph[vtx])
    {
        if (!visited[child])
            flag = flag | isCycle(visited, child, graph, vtx);
        else if (child != parent)
            return true;
    }
    return flag;
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
            if (isCycle(visited, i, graph, -1))
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
        cout << "True";
    else
        cout << "False";

    return 0;
}