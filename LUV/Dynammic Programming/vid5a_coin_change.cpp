#include <bits/stdc++.h>
using namespace std;

int dp[100000];

int coinChangeHelper(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;

    if (dp[amount] != -1)
        return dp[amount];

    int ans = INT_MAX;

    for (auto coin : coins)
        if (amount - coin >= 0)
            ans = min(ans + 0LL, coinChangeHelper(coins, amount - coin) + 1LL);

    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int ans = coinChangeHelper(coins, amount);

    return ans == INT_MAX ? -1 : ans;
}

int main()
{

    return 0;
}