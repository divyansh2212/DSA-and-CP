// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int vtx, vector<int> &st)
{
    visited[vtx] = true;
    for (auto &child : graph[vtx])
    {
        if (visited[child])
            continue;
        dfs(graph, visited, child, st);
    }
    st.push_back(vtx);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<bool> visited(1001, false);
    vector<int> ans;
    
    for (int i = 0; i < nodes; i++)
        if (!visited[i])
            dfs(graph, visited, i, ans);

    reverse(ans.begin(), ans.end());
    return ans;
}
