#include <bits/stdc++.h>
using namespace std;

int dp[5010][310];

int changeHelper(int amount, int idx, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    
    if(idx < 0) return 0;

    if (dp[amount][idx] != -1)
        return dp[amount][idx];

    int ways = 0;

    for (int coin_amt = 0; coin_amt <= amount; coin_amt += coins[idx])
    {
        if (amount - coin_amt >= 0)
            ways += changeHelper(amount - coin_amt, idx - 1, coins);
    }

    return dp[amount][idx] = ways;
}

int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));
    return changeHelper(amount, coins.size() - 1, coins);
}

int main()
{

    return 0;
}