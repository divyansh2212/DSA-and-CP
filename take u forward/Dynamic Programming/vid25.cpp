#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(int length, vector<int> &price, vector<int> &dp)
{
    if (length == 0)
        return 0;
    if (dp[length] != -1)
        return dp[length];

    int cost = INT_MIN;
    for (int to_cut = 1; to_cut <= length; to_cut++)
    {
        cost = max(cost, price[to_cut - 1] + f(length - to_cut, price, dp));
    }
    return dp[length] = cost;
}

int cutRod(vector<int> &price, int n)
{
    // vector<int> dp(n+1, -1);
    // return f(n, price, dp);

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    int cost = INT_MIN;

    for (int l = 1; l < n + 1; l++)
    {
        for (int to_cut = 1; to_cut <= l; to_cut++)
        {
            dp[l] = max(dp[l], price[to_cut - 1] + dp[l - to_cut]);
        }
    }
    return dp[n];
}