#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define ll long long
const int M = 1e9 + 7;

ll f(vector<int> &arr, int target, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];
    ll notPick = f(arr, target, idx - 1, dp);
    ll pick = 0;
    if (target >= arr[idx])
        pick = f(arr, target - arr[idx], idx - 1, dp);

    return dp[idx][target] = (pick + notPick) % M;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total_sum = 0;
    for (auto &it : arr)
        total_sum += it;

    if (total_sum - d < 0 || (total_sum - d) % 2)
        return 0;

    int target = (total_sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    ll ans = f(arr, target, n - 1, dp);

    return (int)ans;
}

// Tabulation
int countPartitions(int n, int d, vector<int> &arr)
{
    int total_sum = 0;
    for (auto &it : arr)
        total_sum += it;

    if ((total_sum - d) < 0 || (total_sum - d) % 2)
        return 0;

    int target = (total_sum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] <= target && arr[0] != 0)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            ll notPick = dp[i - 1][tar];
            ll pick = 0;
            if (tar >= arr[i])
                pick = dp[i - 1][tar - arr[i]];
            dp[i][tar] = (pick + notPick) % M;
        }
    }
    return dp[n - 1][target];
}

// Space Optimization
int countPartitions(int n, int d, vector<int> &arr)
{
    int total_sum = 0;
    for (auto &it : arr)
        total_sum += it;

    if ((total_sum - d) < 0 || (total_sum - d) % 2)
        return 0;

    int target = (total_sum - d) / 2;

    vector<int> prev(target + 1, 0);

    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] <= target && arr[0] != 0)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(target + 1, 0);
        for (int tar = 0; tar <= target; tar++)
        {
            ll notPick = prev[tar];
            ll pick = 0;
            if (tar >= arr[i])
                pick = prev[tar - arr[i]];
            curr[tar] = (pick + notPick) % M;
        }
        prev = curr;
    }
    return prev[target];
}