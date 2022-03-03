#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = take | notTake;
        }
    }

    int mini = 1e9;

    for (int i = 0; i <= sum; i++)
    {
        if (dp[n - 1][i])
        {
            int s1 = i, s2 = sum - i;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}
