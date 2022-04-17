// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> &prices, int idx, int canBuy, int trans, vector<vector<vector<int>>> &dp)
{
    if (idx == prices.size())
        return 0;
    if (trans == 0)
        return 0;
    if (dp[idx][canBuy][trans] != -1)
        return dp[idx][canBuy][trans];

    if (canBuy)
    {
        // buy
        int way1 = -prices[idx] + f(prices, idx + 1, 0, trans, dp);
        // not buy
        int way2 = f(prices, idx + 1, 1, trans, dp);

        return dp[idx][canBuy][trans] = max(way1, way2);
    }
    else
    {
        // sell
        int way1 = prices[idx] + f(prices, idx + 1, 1, trans - 1, dp);
        // not sell
        int way2 = f(prices, idx + 1, 0, trans, dp);

        return dp[idx][canBuy][trans] = max(way1, way2);
    }
}

// int maxProfit(vector<int> &prices, int n)
// {
//     int transactions = 2;
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//     return f(prices, 0, 1, transactions, dp);
// }
int maxProfit(vector<int> &prices, int n)
{
    int transactions = 2;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int canBuy = 0; canBuy < 2; canBuy++)
        {
            for (int trans = 1; trans < 3; trans++)
            {
                if (canBuy)
                {
                    // buy
                    int way1 = -prices[idx] + dp[idx + 1][0][trans];
                    // not buy
                    int way2 = dp[idx + 1][1][trans];

                    dp[idx][canBuy][trans] = max(way1, way2);
                }
                else
                {
                    // sell
                    int way1 = prices[idx] + dp[idx + 1][1][trans - 1];
                    // not sell
                    int way2 = dp[idx + 1][0][trans];

                    dp[idx][canBuy][trans] = max(way1, way2);
                }
            }
        }
    }
    return dp[0][1][2];
}

int maxProfit(vector<int> &prices, int n)
{
    vector<vector<int>> next(2, vector<int>(3, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int canBuy = 0; canBuy < 2; canBuy++)
        {
            for (int trans = 1; trans < 3; trans++)
            {
                if (canBuy)
                {
                    // buy
                    int way1 = -prices[idx] + next[0][trans];
                    // not buy
                    int way2 = next[1][trans];

                    curr[canBuy][trans] = max(way1, way2);
                }
                else
                {
                    // sell
                    int way1 = prices[idx] + next[1][trans - 1];
                    // not sell
                    int way2 = next[0][trans];

                    curr[canBuy][trans] = max(way1, way2);
                }
            }
        }
        next = curr;
    }
    return next[1][2];
}