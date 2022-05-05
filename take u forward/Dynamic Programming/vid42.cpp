// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(int arr[], int idx, int prev_idx, vector<vector<int>> &dp, int n)
{
    if (idx == n)
        return 0;

    if (dp[idx][prev_idx + 1] != -1)
        return dp[idx][prev_idx + 1];

    int way1 = 0, way2 = 0;

    // not take
    way1 = f(arr, idx + 1, prev_idx, dp, n);

    // take
    if (prev_idx == -1 || arr[idx] > arr[prev_idx])
        way2 = 1 + f(arr, idx + 1, idx, dp, n);

    return dp[idx][prev_idx + 1] = max(way1, way2);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(arr, 0, -1, dp, n);
}
