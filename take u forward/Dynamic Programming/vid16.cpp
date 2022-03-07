#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool f(vector<int> &arr, int n, int k)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
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

bool f(vector<int> &arr, int n, int k)
{
    // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    vector<bool> prev(k + 1, false);

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(k + 1, 0);
        for (int target = 1; target <= k; target++)
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

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2)
        return false;

    int target = sum / 2;

    return f(arr, n, target);
}
