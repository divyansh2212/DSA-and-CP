#include <bits/stdc++.h>
using namespace std;
int weights[105], values[105];
int n, w;
long long dp[100005][105];

long long func(int i, int wt)
{
    if (wt == 0)
        return 0;

    if (i == n)
        return 0;

    if (dp[wt][i] != -1)
        return dp[wt][i];

    long long ans = func(i + 1, wt);

    if (wt - weights[i] >= 0)
        ans = max(ans, func(i + 1, wt - weights[i]) + values[i]);

    return dp[wt][i] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;

    for (int i = 0; i < n; i++)
        cin >> weights[i] >> values[i];

    cout << func(0, w);
    return 0;
}