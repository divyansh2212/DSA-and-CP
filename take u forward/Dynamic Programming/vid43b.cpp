// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(int arr[], int n)
{
    int maxAns = 0;
    vector<int> dp(n, 1);

    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[prev] < arr[idx])
                dp[idx] = max(dp[idx], dp[prev] + 1);

            maxAns = max(maxAns, dp[idx]);
        }
    }
    return maxAns;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return f(arr, n);
}
