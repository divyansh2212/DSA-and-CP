#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int h[N];
int dp[N];

int minmCost(int i)
{
    if (i == 1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int cost = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 1)
            cost = min(cost, minmCost(i - j) + abs(h[i] - h[i - j]));
    }

    return dp[i] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << minmCost(n);
    return 0;
}