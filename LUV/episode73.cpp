#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int depth[N], height[N];

void dfs(int vertex, int par = 0)
{
    for (auto child : graph[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}
int main()
{
    int nodes;
    cin >> nodes;

    for (int i = 1; i <= nodes - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);

    for (int i = 1; i <= nodes; i++)
    {
        cout << depth[i] << " " << height[i] << endl;
    }

    return 0;
}