#include <bits/stdc++.h>
using namespace std;
#define ll long long

int func(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = func(i - 1, j, dp);
    int left = func(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // 	return func(m-1, n-1, dp);

    //  Tabulation Form
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = 0, left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}

//  More Optimization
int uniquePaths(int m, int n)
{
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}