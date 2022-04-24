// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> &prices, int idx, int canBuy, vector<vector<int>> &dp)
{
    if (idx >= prices.size())
        return 0;
    if (dp[idx][canBuy] != -1)
        return dp[idx][canBuy];

    int way1 = INT_MIN, way2 = INT_MIN;
    if (canBuy)
    {
        way1 = -prices[idx] + f(prices, idx + 1, 0, dp);
        way2 = f(prices, idx + 1, 1, dp);
    }
    else
    {
        way1 = prices[idx] + f(prices, idx + 2, 1, dp);
        way2 = f(prices, idx + 1, 0, dp);
    }
    return dp[idx][canBuy] = max(way1, way2);
}

// int stockProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return f(prices, 0, 1, dp);
// }

int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int canBuy = 0; canBuy < 2; canBuy++)
        {
            int way1 = INT_MIN, way2 = INT_MIN;
            if (canBuy)
            {
                way1 = -prices[idx] + dp[idx + 1][0];
                way2 = dp[idx + 1][1];
            }
            else
            {
                way1 = prices[idx] + dp[idx + 2][1];
                way2 = dp[idx + 1][0];
            }
            dp[idx][canBuy] = max(way1, way2);
        }
    }
    return dp[0][1];
}