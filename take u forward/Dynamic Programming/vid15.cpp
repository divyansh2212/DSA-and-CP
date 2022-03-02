#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool func(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx < 0)
        return false;
    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool notTake = func(idx - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[idx])
        take = func(idx - 1, target - arr[idx], arr, dp);

    return dp[idx][target] = (take | notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    //     vector<vector<int>> dp(n , vector<int>(k + 1, -1));
    //     return func(n - 1, k, arr, dp);
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target < k + 1; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = take | notTake;
        }
    }
    return dp[n - 1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target < k + 1; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[i] <= target)
                take = prev[target - arr[i]];
            curr[target] = take | notTake;
        }
        prev = curr;
    }
    return prev[k];
}