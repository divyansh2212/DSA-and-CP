#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> &num, int tar, int idx, vector<vector<int>> &dp)
{
    if (tar == 0)
        return 1;
    if (idx == 0)
        return num[0] == tar;

    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    int notpick = f(num, tar, idx - 1, dp);
    int pick = 0;
    if (tar >= num[idx])
        pick = f(num, tar - num[idx], idx - 1, dp);

    return dp[idx][tar] = pick + notpick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    //     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    //     return f(num, tar, n - 1, dp);

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= tar; target++)
        {
            int notpick = dp[i - 1][target];
            int pick = 0;
            if (target >= num[i])
                pick = dp[i - 1][target - num[i]];
            dp[i][target] = pick + notpick;
        }
    }

    return dp[n - 1][tar];
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<int> prev(tar + 1, 0);

    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(tar + 1, 0);
        for (int target = 1; target <= tar; target++)
        {
            int notpick = prev[target];
            int pick = 0;
            if (target >= num[i])
                pick = prev[target - num[i]];
            curr[target] = pick + notpick;
        }
        prev = curr;
    }

    return prev[tar];
}