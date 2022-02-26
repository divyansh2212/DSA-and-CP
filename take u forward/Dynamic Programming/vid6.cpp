// DP  Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences
#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx < 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int sum = 0;
    sum = max(sum, func(nums, idx - 2, dp) + nums[idx]);
    sum = max(sum, func(nums, idx - 1, dp));

    return dp[idx] = sum;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // Bottom-Up Approach using space-optimization

    int prev = nums[0], prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;

        int notTake = prev;

        int curr = max(take, notTake);

        prev2 = prev, prev = curr;
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();

    vector<int> dp(n, -1);
    //     return func(nums, n-1, dp);

    // Bottom-Up Approach
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += dp[i - 2];

        int notTake = dp[i - 1];

        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}