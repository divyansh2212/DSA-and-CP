#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (idx == 0)
        return (w / weight[0]) * profit[0];
    if (dp[idx][w] != -1)
        return dp[idx][w];

    int notTake = f(idx - 1, w, profit, weight, dp);
    int take = 0;
    if (w - weight[idx] >= 0)
        take = profit[idx] + f(idx, w - weight[idx], profit, weight, dp);

    return dp[idx][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // return f(n - 1, w, profit, weight, dp);

    vector<int> prev(w + 1, 0);

    for (int i = 0; i <= w; i++)
        prev[i] = (i / weight[0]) * profit[0];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(w + 1, 0);
        for (int wt = 0; wt <= w; wt++)
        {
            int notTake = prev[wt];
            int take = 0;
            if (wt - weight[i] >= 0)
                take = profit[i] + curr[wt - weight[i]];

            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}


// More Space Optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // return f(n - 1, w, profit, weight, dp);

    vector<int> prev(w + 1, 0);

    for (int i = 0; i <= w; i++)
        prev[i] = (i / weight[0]) * profit[0];

    for (int i = 1; i < n; i++)
    {
        // vector<int> curr(w + 1, 0);
        for (int wt = 0; wt <= w; wt++)
        {
            int notTake = prev[wt];
            int take = 0;
            if (wt - weight[i] >= 0)
                take = profit[i] + prev[wt - weight[i]];

            prev[wt] = max(take, notTake);
        }
        // prev = curr;
    }
    return prev[w];
}
