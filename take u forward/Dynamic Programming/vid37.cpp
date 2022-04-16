// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

long f(long *vals, int idx, int canBuy, int n, vector<vector<long>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][canBuy] != -1)
        return dp[idx][canBuy];

    if (canBuy)
    {
        // buy
        long way1 = f(vals, idx + 1, 0, n, dp) - vals[idx];

        // not buy
        long way2 = f(vals, idx + 1, 1, n, dp);

        return dp[idx][canBuy] = max(way1, way2);
    }
    else
    {
        // sell
        long way1 = vals[idx] + f(vals, idx + 1, 1, n, dp);

        // not sell
        long way2 = f(vals, idx + 1, 0, n, dp);

        return dp[idx][canBuy] = max(way1, way2);
    }
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return f(values, 0, 1, n, dp);
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    for (long i = n - 1; i >= 0; i--)
    {
        for (long canBuy = 0; canBuy < 2; canBuy++)
        {
            if (canBuy)
            {
                // buy
                long way1 = dp[i + 1][0] - values[i];

                // not buy
                long way2 = dp[i + 1][1];

                dp[i][canBuy] = max(way1, way2);
            }
            else
            {
                // sell
                long way1 = values[i] + dp[i + 1][1];

                // not sell
                long way2 = dp[i + 1][0];

                dp[i][canBuy] = max(way1, way2);
            }
        }
    }
    return dp[0][1];
}

long getMaximumProfit(long *values, int n)
{
    vector<long> next(2, 0);

    for (long i = n - 1; i >= 0; i--)
    {
        vector<long> curr(2, 0);
        for (long canBuy = 0; canBuy < 2; canBuy++)
        {
            if (canBuy)
            {
                // buy
                long way1 = next[0] - values[i];

                // not buy
                long way2 = next[1];

                curr[canBuy] = max(way1, way2);
            }
            else
            {
                // sell
                long way1 = values[i] + next[1];

                // not sell
                long way2 = next[0];

                curr[canBuy] = max(way1, way2);
            }
        }
        next = curr;
    }
    return next[1];
}