#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

ll func(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (mat[i][j] == -1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    ll up = func(i - 1, j, mat, dp);
    ll left = func(i, j - 1, mat, dp);

    return dp[i][j] = (up + left) % M;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return func(n - 1, m - 1, mat, dp);

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (mat[i][j] == -1)
                dp[i][j] = 0;
            else
            {
                ll up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = (up + left) % M;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// More Space Optimization
#define ll long long
const int M = 1e9 + 7;

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else if (mat[i][j] == -1)
                curr[j] = 0;
            else
            {
                ll up = 0, left = 0;
                up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = (up + left) % M;
            }
        }
        prev = curr;
    }

    return prev[m - 1];
}