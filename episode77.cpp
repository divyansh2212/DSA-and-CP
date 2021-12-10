// Edge deletion Technique
// To maximise the product of sum of values of two trees after edge deletion
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
vector<int> g[N];
int subtrees_sum[N];
int val[N];

void dfs(int vtx, int par = 0)
{
    subtrees_sum[vtx] += val[vtx];
    for (auto child : g[vtx])
    {
        if (child == par)
            continue;
        dfs(child, vtx);
        subtrees_sum[vtx] += subtrees_sum[child];
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
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    // Tree is rooted at node 1
    dfs(1, 0);
    long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int part1 = subtrees_sum[i];
        int part2 = subtrees_sum[1] - part1;
        ans = max(ans, (part1 * 1LL * part2) % M);
    }

    cout << ans;
    return 0;
}