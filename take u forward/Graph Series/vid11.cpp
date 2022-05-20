// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, int vtx, vector<int> &color, bool &flag)
    {
        if (color[vtx] == -1)
            color[vtx] = 0;
            
        for (auto &child : graph[vtx])
        {
            if (color[child] == -1)
            {
                color[child] = !color[vtx];
                dfs(graph, child, color, flag);
            }
            else if (color[child] == color[vtx])
                flag = false;
        }
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        bool flag = true;
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
            if (color[i] == -1)
                dfs(graph, i, color, flag);
        return flag;
    }
};