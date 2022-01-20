// B. Greg and Graph
// Example for Floyd Warshall
// https://codeforces.com/problemset/problem/295/B?mobile=false
#include <bits/stdc++.h>
using namespace std;
const int N = 500;
long long dist[N][N];
vector<long long> ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dist[i][j];

    vector<int> del_order(n);
    for (int i = 0; i < n; i++)
        cin >> del_order[i];

    reverse(del_order.begin(), del_order.end());

    for (int k = 0; k < n; k++)
    {
        int k_v = del_order[k];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }

        long long sum = 0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
                sum += dist[del_order[i]][del_order[j]];
        }
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    for (auto sums : ans)
        cout << sums << " ";
    return 0;
}