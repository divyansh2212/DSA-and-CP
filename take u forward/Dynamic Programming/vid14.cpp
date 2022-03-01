#include <bits/stdc++.h>
using namespace std;
#define ll long long

int func(int i, int j1, int j2, vector<vector<int>> &grid, int dp[51][51][51])
{
    int n = grid.size(), m = grid[0].size();
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxSum = 0;
    for (int move1 = -1; move1 <= 1; move1++)
    {
        for (int move2 = -1; move2 <= 1; move2++)
        {
            int curr = 0;
            if (j1 == j2)
                curr += grid[i][j1];
            else
                curr += grid[i][j1] + grid[i][j2];
            curr += func(i + 1, j1 + move1, j2 + move2, grid, dp);
            maxSum = max(maxSum, curr);
        }
    }

    return dp[i][j1][j2] = maxSum;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    int dp[51][51][51];
    memset(dp, -1, sizeof(dp));

    // for (int j1 = 0; j1 < c; j1++)
    // {
    //     for (int j2 = 0; j2 < c; j2++)
    //     {
    //         if (j1 == j2)
    //             dp[r - 1][j1][j2] = grid[r - 1][j1];
    //         else
    //             dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
    //     }
    // }

    // for (int i = r-2; i >= 0; i--)
    // {
    //     for (int j1 = 0; j1 < c; j1++)
    //     {
    //         for (int j2 = 0; j2 < c; j2++)
    //         {
    //             dp[i][j1][j2] = dp[i-1][j1][j2];
    //         }

    //     }

    // }
}