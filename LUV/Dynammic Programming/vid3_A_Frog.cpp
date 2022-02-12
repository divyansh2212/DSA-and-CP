#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int dp[N];

int minmCost(int n)
{
    if (n == 1)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int cost = INT_MAX;

    cost = min(cost, minmCost(n - 1) + abs(h[n] - h[n - 1]));

    if (n > 2)
        cost = min(cost, minmCost(n - 2) + abs(h[n] - h[n - 2]));

    return dp[n] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << minmCost(n);
    return 0;
}