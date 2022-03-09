#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findWays(int n, int d, vector<int> &arr)
{
    int tot = 0;
    for (auto &it : arr)
        tot += it;

    if ((tot - d) < 0 || (tot - d) % 2)
        return 0;

    int target = (tot - d) / 2;

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
            int notTake = dp[i - 1][tar];
            int take = 0;
            if (tar >= arr[i])
                take = dp[i - 1][tar - arr[i]];

            dp[i][tar] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

int targetSum(int n, int target, vector<int> &arr)
{
    return findWays(n, target, arr);
}
