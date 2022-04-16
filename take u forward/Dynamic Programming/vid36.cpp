// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maximumProfit(vector<int> &prices)
{
    int profit = 0;
    int minimal = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int currprofit = prices[i] - minimal;
        profit = max(profit, currprofit);
        minimal = min(minimal, prices[i]);
    }
    return profit;
}