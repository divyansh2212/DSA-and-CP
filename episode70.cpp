#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool visited[N];
// O(v+E)
void dfs(int vertex)
{
    if (visited[vertex])
        return;
    visited[vertex] = true;
    // Take action on vertex after entering the vertex
    for (auto child : g[vertex])
    {
        // Take action on the child before entering the child node
        dfs(child);
        // Take action on the child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    return 0;
}