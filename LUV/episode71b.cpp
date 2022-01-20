// To detect loop in a graph

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];

bool dfs(int vertex, int parent)
{
    visited[vertex] = true;
    bool isLoopExists = false;
    for (auto child : graph[vertex])
    {
        if (visited[child] && child == parent)
            continue;
        if (visited[child])
            return true;
        isLoopExists = isLoopExists | dfs(child, vertex);
    }
    return isLoopExists;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bool isLoopExists = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl;
    return 0;
}