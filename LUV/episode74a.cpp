// Brute Force Approach
// To calculate sum of subtree
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
void dfs(int vertex, int par, int &sum)
{
    sum += vertex;
    for (auto child : g[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex, sum);
    }
}
int main()
{
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    //  int v;
    // cin >> v;
    int sum = 0;
    dfs(v, 4, sum);
    cout << sum;
    return 0;
}