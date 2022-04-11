// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Edit Distance

// You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.
// Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character

int f(string &str1, string &str2, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 < 0)
        return idx2 + 1;

    if (idx2 < 0)
        return idx1 + 1;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (str1[idx1] == str2[idx2])
        return dp[idx1][idx2] = f(str1, str2, idx1 - 1, idx2 - 1, dp);

    else
    {
        // insert
        int way1 = 1 + f(str1, str2, idx1, idx2 - 1, dp);

        // delete
        int way2 = 1 + f(str1, str2, idx1 - 1, idx2, dp);

        // replace
        int way3 = 1 + f(str1, str2, idx1 - 1, idx2 - 1, dp);

        return dp[idx1][idx2] = min(way1, min(way2, way3));
    }
}

// int editDistance(string str1, string str2)
// {
// int n = str1.length(), m = str2.length();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return f(str1, str2, n - 1, m - 1, dp);
// }

int editDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return f(str1, str2, n - 1, m - 1, dp);

    for (int i = 1; i < n + 1; i++)
        dp[i][0] = i;

    for (int i = 1; i < m + 1; i++)
        dp[0][i] = i;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                // insert
                int way1 = 1 + dp[i][j - 1];

                // delete
                int way2 = 1 + dp[i - 1][j];

                // replace
                int way3 = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(way1, min(way2, way3));
            }
        }
    }

    return dp[n][m];
}

int editDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    vector<int> prev(m + 1, 0);

    // for (int i = 1; i < n + 1; i++)
    //     dp[i][0] = i;

    for (int i = 1; i < m + 1; i++)
        prev[i] = i;

    for (int i = 1; i < n + 1; i++)
    {
        vector<int> curr(m + 1, 0);
        // imp
        curr[0] = i;
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];
            else
            {
                // insert
                int way1 = 1 + curr[j - 1];

                // delete
                int way2 = 1 + prev[j];

                // replace
                int way3 = 1 + prev[j - 1];

                curr[j] = min(way1, min(way2, way3));
            }
        }
        prev = curr;
    }
    return prev[m];
}