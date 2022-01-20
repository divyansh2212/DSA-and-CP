#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int p[N];

void dfs(int vtx, int par = -1)
{
    p[vtx] = par;
    for (auto child : g[vtx])
    {
        if (child == par)
            continue;
        dfs(child, vtx);
    }
}
vector<int> path(int node)
{
    vector<int> ans;
    while (node != -1)
    {
        ans.push_back(node);
        node = p[node];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    int x, y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int min_ln = min(path_x.size(), path_y.size());

    int lca = -1;
    for (int i = 0; i < min_ln; i++)
    {
        if (path_x[i] == path_y[i])
            lca = path_x[i];
        else
            break;
    }
    cout << lca;
    return 0;
}