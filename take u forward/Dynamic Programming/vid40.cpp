// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// DP 39. Buy and Sell Stocks With Cooldown | Recursion to Space Optimisation

int f(vector<int> &prices, int idx, int canBuy, int coolDown, vector<vector<vector<int>>> &dp)
{
    if (idx == prices.size())
        return 0;
    if (dp[idx][canBuy][coolDown] != -1)
        return dp[idx][canBuy][coolDown];

    int way1 = INT_MIN, way2 = INT_MIN;
    if (canBuy)
    {
        if (coolDown)
            way1 = f(prices, idx + 1, 1, 0, dp);
        else
        {
            way1 = -prices[idx] + f(prices, idx + 1, 0, coolDown, dp);
            way2 = f(prices, idx + 1, 1, coolDown, dp);
        }
    }
    else
    {
        way1 = prices[idx] + f(prices, idx + 1, 1, 1, dp);
        way2 = f(prices, idx + 1, 0, 0, dp);
    }
    return dp[idx][canBuy][coolDown] = max(way1, way2);
}

int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
    return f(prices, 0, 1, 0, dp);
}