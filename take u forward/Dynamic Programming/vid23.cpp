#include <bits/stdc++.h>
using namespace std;
#define ll long

ll f(vector<int> &nums, int idx, int value, vector<vector<ll>> &dp)
{
    if (idx == 0)
    {
        if (value % nums[0] == 0)
            return 1;
        return 0;
    }
    if (dp[idx][value] != -1)
        return dp[idx][value];

    ll notTake = f(nums, idx - 1, value, dp);
    ll take = 0;
    if (nums[idx] <= value)
        take = f(nums, idx, value - nums[idx], dp);

    return dp[idx][value] = take + notTake;
}

ll countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = denominations[i];

    // vector<vector<ll>> dp(n, vector<ll>(value + 1, -1));
    // return f(nums, n - 1, value, dp);

    vector<vector<ll>> dp(n, vector<ll>(value + 1, 0));

    for (int i = 0; i <= value; i++)
    {
        if (i % nums[0] == 0)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= value; tar++)
        {
            ll notTake = dp[i - 1][tar];
            ll take = 0;
            if (nums[i] <= tar)
                take = dp[i][tar - nums[i]];

            dp[i][tar] = take + notTake;
        }
    }
    return dp[n - 1][value];
}