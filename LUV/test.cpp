#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bool visited[N];
int curr = 0;

void dfs(vector<vector<pair<int, int>>> g, int vtx)
{
    visited[vtx] = true;
    for (auto child : g[vtx])
    {
        if (visited[child.first])
            continue;
        dfs(g, child.first);
        curr = (curr | child.second);
    }
}

void reset()
{
    for (int i = 0; i < N; i++)
        visited[i] = false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        vector<vector<pair<int, int>>> g(N);
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y, wt;
            cin >> x >> y >> wt;
            g[x].push_back({y, wt});
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            reset();
            curr = 0;
            dfs(g, i);
            ans = min(ans, curr);
        }
        cout << ans << endl;
    }

    return 0;
}