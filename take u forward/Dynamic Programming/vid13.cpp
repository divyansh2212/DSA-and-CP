#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int func(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
// {
//     if (j < 0 || j >= matrix[0].size())
//         return -1e8;
//     if (i == 0)
//         return matrix[i][j];
//     if(dp[i][j] != -1e9) return dp[i][j];

//     int u = func(i - 1, j, matrix, dp) + matrix[i][j];
//     int ld = func(i - 1, j - 1, matrix, dp) + matrix[i][j];
//     int rd = func(i - 1, j + 1, matrix, dp) + matrix[i][j];

//     return dp[i][j] = max(u, max(ld, rd));
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int maxmProfit = -1e8, n = matrix.size(), m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, -1e9));
//     for (int j = 0; j < m; j++)
//     {
//         maxmProfit = max(maxmProfit, func(n-1, j, matrix, dp));
//     }
//     return maxmProfit;
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int maxmProfit = -1e8, n = matrix.size(), m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, -1e9));
//     for (int j = 0; j < m; j++)
//         dp[0][j] = matrix[0][j];

//     for(int i = 1; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             int down = -1e8, ld = -1e8, rd = -1e8;
//             down = matrix[i][j] + dp[i-1][j];
//             if(j + 1 < m)
//             ld = matrix[i][j] + dp[i-1][j+1];
//             if(j > 0)
//             rd = matrix[i][j]  + dp[i-1][j-1];

//             dp[i][j] = max(down, max(ld, rd));
//         }
//     }

//     int maxi = -1e8;
//     for(int j = 0; j < m; j++)
//         maxi = max(maxi, dp[n-1][j]);
//     return maxi;
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int maxmProfit = -1e8, n = matrix.size(), m = matrix[0].size();
    vector<int> prev(m, -1e8);
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, -1e8);
        for (int j = 0; j < m; j++)
        {
            int down = -1e8, ld = -1e8, rd = -1e8;
            down = matrix[i][j] + prev[j];
            if (j + 1 < m)
                ld = matrix[i][j] + prev[j + 1];
            if (j > 0)
                rd = matrix[i][j] + prev[j - 1];

            curr[j] = max(down, max(ld, rd));
        }
        prev = curr;
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prev[j]);
    return maxi;
}