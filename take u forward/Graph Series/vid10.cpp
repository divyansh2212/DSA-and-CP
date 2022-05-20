// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Bipartite Graph (BFS) | Graph Coloring

class Solution
{
public:
    void bfs(vector<vector<int>> &graph, vector<int> &color, int vtx, bool &flag)
    {
        queue<int> q;
        q.push(vtx);
        color[vtx] = 0;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto &child : graph[top])
            {
                if (color[child] == -1)
                {
                    q.push(child);
                    color[child] = !color[top];
                }
                else if (color[child] == color[top])
                {
                    flag = false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        bool flag = true;

        for (int i = 0; i < n; i++)
            if (color[i] == -1)
                bfs(graph, color, i, flag);

        return flag;
    }
};