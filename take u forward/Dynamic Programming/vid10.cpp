#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll func(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll Sum = 1e9;
    Sum = min(Sum, func(grid, i - 1, j, dp) + grid[i][j]);
    Sum = min(Sum, func(grid, i, j - 1, dp) + grid[i][j]);

    return dp[i][j] = Sum;
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    //     ll ans = func(grid, n - 1, m - 1, dp);

    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int left = 1e9, up = 1e9;

            if (j > 0)
                left = dp[i][j - 1];
            if (i > 0)
                up = dp[i - 1][j];

            if (dp[i][j] == -1)
                dp[i][j] = min(left, up) + grid[i][j];
            else
                dp[i][j] = min(dp[i][j], min(left, up) + grid[i][j]);
        }
    }
    return dp[n - 1][m - 1];
    //     return (int)ans;
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<int> prev(m, -1);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, -1);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[0] = grid[0][0];
                continue;
            }
            int left = 1e9, up = 1e9;

            if (j > 0)
                left = curr[j - 1];
            if (i > 0)
                up = prev[j];

            if (curr[j] == -1)
                curr[j] = min(left, up) + grid[i][j];
            else
                curr[j] = min(curr[j], min(left, up) + grid[i][j]);
        }
        prev = curr;
    }
    return prev[m - 1];
}