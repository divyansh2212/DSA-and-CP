// Pre computation using dfs
// To calculate sum of all subtrees and even counts in all sub trees
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int subtrees_sum[N];
int even_cnt[N];

void dfs(int vertex, int par = 0)
{
    if (vertex % 2 == 0)
        even_cnt[vertex]++;
    subtrees_sum[vertex] += vertex;
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);

        subtrees_sum[vertex] += subtrees_sum[child];
        even_cnt[vertex] += even_cnt[child];
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

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << subtrees_sum[i] << " " << even_cnt[i] << endl;
    }

    return 0;
}