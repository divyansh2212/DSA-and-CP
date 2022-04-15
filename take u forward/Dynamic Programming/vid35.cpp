// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool f(string &pattern, string &text, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 < 0 && idx2 < 0)
        return true;

    if (idx1 < 0)
        return false;

    if (idx2 < 0)
    {
        for (int i = 0; i < idx1 + 1; i++)
            if (pattern[i] != '*')
                return false;
        return true;
    }

    if (dp[idx1][idx2] != -1)
        return (bool)dp[idx1][idx2];

    if (pattern[idx1] == text[idx2] || pattern[idx1] == '?')
        return dp[idx1][idx2] = f(pattern, text, idx1 - 1, idx2 - 1, dp);

    else if (pattern[idx1] == '*')
    {
        bool way2 = f(pattern, text, idx1, idx2 - 1, dp);
        bool way3 = f(pattern, text, idx1 - 1, idx2, dp);

        return dp[idx1][idx2] = (way2 | way3);
    }
    else
        return dp[idx1][idx2] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // return f(pattern, text, n - 1, m - 1, dp);

    dp[0][0] = true;
    for (int i = 1; i < m + 1; i++)
        dp[0][i] = false;

    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = true;
        for (int j = 1; j < i + 1; j++)
        {
            if (pattern[j - 1] != '*')
                dp[i][0] = false;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (pattern[i - 1] == '*')
            {
                bool way2 = dp[i][j - 1];
                bool way3 = dp[i - 1][j];
                dp[i][j] = (way2 | way3);
            }
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<int> prev(m + 1, 0);

    prev[0] = true;
    for (int i = 1; i < m + 1; i++)
        prev[i] = false;

    for (int i = 1; i < n + 1; i++)
    {
        vector<int> curr(m + 1, 0);

        curr[0] = true;
        for (int j = 1; j < i + 1; j++)
            if (pattern[j - 1] != '*')
                curr[0] = false;

        for (int j = 1; j < m + 1; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                curr[j] = prev[j - 1];

            else if (pattern[i - 1] == '*')
            {
                bool way2 = curr[j - 1];
                bool way3 = prev[j];
                curr[j] = (way2 | way3);
            }
            else
                curr[j] = false;
        }
        prev = curr;
    }

    return prev[m];
}