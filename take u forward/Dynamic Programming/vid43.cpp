// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            int way1 = 0, way2 = 0;

            // not take
            way1 = dp[idx + 1][prev_idx + 1];

            // take
            if (prev_idx == -1 || arr[idx] > arr[prev_idx])
                way2 = 1 + dp[idx + 1][idx + 1];

            dp[idx][prev_idx + 1] = max(way1, way2);
        }
    }
    return dp[0][0];
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(n + 1, 0);
        for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            int way1 = 0, way2 = 0;

            // not take
            way1 = next[prev_idx + 1];

            // take
            if (prev_idx == -1 || arr[idx] > arr[prev_idx])
                way2 = 1 + next[idx + 1];

            curr[prev_idx + 1] = max(way1, way2);
        }
        next = curr;
    }
    return next[0];
}
