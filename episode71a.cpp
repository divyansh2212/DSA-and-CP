// To find connected components in a forest

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
vector<vector<int>> ccs;
vector<int> current_cc;
bool visited[N];

void dfs(int vertex)
{
    if (visited[vertex])
        return;
    current_cc.push_back(vertex);
    visited[vertex] = true;
    for (auto child : graph[vertex])
    {
        dfs(child);
    }
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

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        current_cc.clear();
        cnt++;
        dfs(i);
        ccs.push_back(current_cc);
    }

    cout << cnt << endl; // ccs.size()
    for (auto cc : ccs)
    {
        for (auto node : cc)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}