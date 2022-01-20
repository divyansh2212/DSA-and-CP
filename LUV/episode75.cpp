// To find diameter of a tree using O(N) Time complexity
// 1. With any node, find maxm depth node
// 2. With that node as root, find maxm depth
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int vtx, int par = 0)
{
    for (auto child : g[vtx])
    {
        if (child == par)
            continue;
        depth[child] = depth[vtx] + 1;
        dfs(child, vtx);
    }
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

    // We can take any node to run dfs
    dfs(2);
    int mx_depth = -1, mx_d_node;
    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i])
        {
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }

    mx_depth = -1;
    dfs(mx_d_node);
    for (int i = 1; i <= n; i++)
        if (mx_depth < depth[i])
            mx_depth = depth[i];

    cout << mx_depth;
    return 0;
}