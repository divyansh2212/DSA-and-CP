// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Another approach than previous video

int f(vector<int> &prices, int idx, int transactions, int k, vector<vector<int>> &dp)
{
    if (idx == prices.size())
        return 0;
    if (transactions == 2 * k)
        return 0;
    if (dp[idx][transactions] != -1)
        return dp[idx][transactions];

    if (transactions % 2 == 0)
    {
        int way1 = -prices[idx] + f(prices, idx + 1, transactions + 1, k, dp);
        int way2 = f(prices, idx + 1, transactions, k, dp);
        return dp[idx][transactions] = max(way1, way2);
    }
    else
    {
        int way1 = prices[idx] + f(prices, idx + 1, transactions + 1, k, dp);
        int way2 = f(prices, idx + 1, transactions, k, dp);
        return dp[idx][transactions] = max(way1, way2);
    }
}

// int maximumProfit(vector<int> &prices, int n, int k)
// {
//     vector<vector<int>> dp(n, vector<int>(2 * k, -1));
//     return f(prices, 0, 0, k, dp);
// }

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int trans = 2 * k - 1; trans >= 0; trans--)
        {
            if (trans % 2 == 0)
            {
                int way1 = -prices[idx] + dp[idx + 1][trans + 1];
                int way2 = dp[idx + 1][trans];
                dp[idx][trans] = max(way1, way2);
            }
            else
            {
                int way1 = prices[idx] + dp[idx + 1][trans + 1];
                int way2 = dp[idx + 1][trans];
                dp[idx][trans] = max(way1, way2);
            }
        }
    }
    return dp[0][0];
}
