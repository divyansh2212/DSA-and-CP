#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>> &triangle, int n,
         vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];

    int mnm = 1e9;
    mnm = min(mnm, func(i + 1, j, triangle, n, dp) + triangle[i][j]);
    mnm = min(mnm, func(i + 1, j + 1, triangle, n, dp) + triangle[i][j]);

    return mnm;
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // 	return func(0, 0, triangle, n, dp);

    // Tabulation Form
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = dp[i + 1][j] + triangle[i][j];
            int dg = dp[i + 1][j + 1] + triangle[i][j];

            dp[i][j] = min(down, dg);
        }
    }
    return dp[0][0];
}

// More Space Optimization

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> prev(n);
    for (int i = 0; i < n; i++)
        prev[i] = triangle[n - 1][i];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n);
        for (int j = i; j >= 0; j--)
        {
            int down = prev[j] + triangle[i][j];
            int dg = prev[j+1] + triangle[i][j];
            curr[j] = min(down, dg);
        }
        prev = curr;
    }
    return prev[0];
}