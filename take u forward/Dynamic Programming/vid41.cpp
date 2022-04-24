// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> &prices, int idx, int canBuy, int fee, vector<vector<int>> &dp)
{
    if (idx == prices.size())
        return 0;
    if (dp[idx][canBuy] != -1)
        return dp[idx][canBuy];

    if (canBuy)
        return dp[idx][canBuy] = max(f(prices, idx + 1, 1, fee, dp), -prices[idx] + f(prices, idx + 1, 0, fee, dp));
    else
        return dp[idx][canBuy] = max(prices[idx] + f(prices, idx + 1, 1, fee, dp) - fee, f(prices, idx + 1, 0, fee, dp));
}

// int maximumProfit(int n, int fee, vector<int> &prices)
// {
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return f(prices, 0, 1, fee, dp);
// }

int maximumProfit(int n, int fee, vector<int> &prices)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        dp[idx][1] = max(dp[idx + 1][1], -prices[idx] + dp[idx + 1][0]);

        dp[idx][0] = max(prices[idx] + dp[idx + 1][1] - fee, dp[idx + 1][0]);
    }

    return dp[0][1];
}

int maximumProfit(int n, int fee, vector<int> &prices)
{
    vector<int> next(2, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(2, 0);

        curr[1] = max(next[1], -prices[idx] + next[0]);
        curr[0] = max(prices[idx] + next[1] - fee, next[0]);

        next = curr;
    }

    return next[1];
}
