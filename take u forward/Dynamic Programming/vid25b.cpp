#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> &price, int length, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
        return length * price[0];

    if (dp[idx][length] != -1)
        return dp[idx][length];

    int notTake = f(price, length, idx - 1, dp);
    int take = 0;
    // Here idx + 1 is the length of the curr idx
    if (length >= idx + 1)
        take = price[idx] + f(price, length - (idx + 1), idx, dp);

    return dp[idx][length] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return f(price, n, n - 1, dp);

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = price[0] * i;

    for (int i = 1; i < n; i++)
    {
        for (int len = 0; len <= n; len++)
        {
            int notTake = dp[i - 1][len];
            int take = 0;
            if (len - (i + 1) >= 0)
                take = price[i] + dp[i][len - (i + 1)];

            dp[i][len] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}
