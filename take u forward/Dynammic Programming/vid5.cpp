#include <bits/stdc++.h>
using namespace std;

int minmCost(vector<int> &arr, int k, int idx, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int cost = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
            cost = min(cost, minmCost(arr, k, idx - i, dp) + abs(arr[idx] - arr[idx - i]));
    }
    return dp[idx] = cost;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n + 1, 0);
    cout << minmCost(arr, k, n - 1, dp);

    return 0;
}