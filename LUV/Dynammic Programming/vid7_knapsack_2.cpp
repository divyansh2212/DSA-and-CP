#include <bits/stdc++.h>
using namespace std;
int n, w;
int weights[105], values[105];
long long dp[105][100005];

long long func(int idx, int value_left)
{
    if (value_left == 0)
        return 0;

    if (idx < 0)
        return 1e15;

    if (dp[idx][value_left] != -1)
        return dp[idx][value_left];

    long long ans = func(idx - 1, value_left);

    if (value_left - values[idx] >= 0)
        ans = min(func(idx - 1, value_left - values[idx]) + weights[idx], ans);

    return dp[idx][value_left] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;

    for (int i = 0; i < n; i++)
        cin >> weights[i] >> values[i];

    int max_val = 1e5;

    for (int i = max_val; i >= 0; i--)
    {
        if (func(n - 1, i) <= w)
        {
            cout << i;
            break;
        }
    }

    return 0;
}