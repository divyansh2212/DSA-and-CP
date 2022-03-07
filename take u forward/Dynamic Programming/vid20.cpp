#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<int> weight, vector<int> value, int W, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (weight[0] <= W)
            return value[0];
        else
            return 0;
    }
    if (dp[idx][W] != -1)
        return dp[idx][W];

    int notTake = f(weight, value, W, idx - 1, dp);
    int take = -1e8;
    if (W - weight[idx] >= 0)
        take = value[idx] + f(weight, value, W - weight[idx], idx - 1, dp);

    return dp[idx][W] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return f(weight, value, maxWeight, n - 1, dp);
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // For stealing weight[0], we should have minm capacity of bag is weight[0];
    for (int wt = weight[0]; wt <= maxWeight; wt++)
        dp[0][wt] = value[0];

    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int notTake = dp[i - 1][wt];
            int take = -1e8;
            if (weight[i] <= wt)
                take = dp[i - 1][wt - weight[i]] + value[i];

            dp[i][wt] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int wt = weight[0]; wt <= maxWeight; wt++)
        prev[wt] = value[0];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(maxWeight + 1, 0);
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int notTake = prev[wt];
            int take = -1e8;
            if (weight[i] <= wt)
                take = prev[wt - weight[i]] + value[i];

            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// More space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int wt = weight[0]; wt <= maxWeight; wt++)
        prev[wt] = value[0];

    for (int i = 1; i < n; i++)
    {
        // Reversed the loop
        for (int wt = maxWeight; wt >= 0; wt--)
        {
            int notTake = prev[wt];
            int take = -1e8;
            if (weight[i] <= wt)
                take = prev[wt - weight[i]] + value[i];

            prev[wt] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}