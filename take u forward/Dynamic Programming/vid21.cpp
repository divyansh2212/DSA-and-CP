#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> &num, int target, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target % num[0] == 0)
            return (target / num[0]);
        return 1e8;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = f(num, target, idx - 1, dp);
    int take = 1e8;
    if (num[idx] <= target)
        take = 1 + f(num, target - num[idx], idx, dp);

    return dp[idx][target] = min(take, notTake);
}

int minimumElements(vector<int> &num, int target)
{
    int n = num.size();
    //     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    //     int ans =  f(num, target, n - 1, dp);
    //     if(ans >= 1e8) return -1;
    //     else return ans;

    vector<vector<int>> dp(n, vector<int>(target + 1, 1e8));

    for (int T = 0; T <= target; T++)
    {
        if (T % num[0] == 0)
            dp[0][T] = T / num[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = dp[idx - 1][tar];
            int take = 1e8;
            if (tar >= num[idx])
                take = 1 + dp[idx][tar - num[idx]];

            dp[idx][tar] = min(take, notTake);
        }
    }
    int ans = dp[n - 1][target];
    if (ans >= 1e8)
        return -1;
    return ans;
}

int minimumElements(vector<int> &num, int target)
{
    int n = num.size();

    vector<int> prev(target + 1, 1e8);

    for (int T = 0; T <= target; T++)
    {
        if (T % num[0] == 0)
            prev[T] = T / num[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(target + 1, 0);
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = prev[tar];
            int take = 1e8;
            if (tar >= num[idx])
                take = 1 + curr[tar - num[idx]];

            curr[tar] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[target];
    if (ans >= 1e8)
        return -1;
    return ans;
}