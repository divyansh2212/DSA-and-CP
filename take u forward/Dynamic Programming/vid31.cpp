// Jai Shree Babosa!

// Minimum Insertions/Deletions to Convert String A to String B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(string &str, string &ptr, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 == 0 || idx2 == 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (str[idx1 - 1] == ptr[idx2 - 1])
        return dp[idx1][idx2] = 1 + f(str, ptr, idx1 - 1, idx2 - 1, dp);
    else
        return dp[idx1][idx2] = max(f(str, ptr, idx1 - 1, idx2, dp), f(str, ptr, idx1, idx2 - 1, dp));
}

int canYouMake(string &str, string &ptr)
{
    int n = str.length(), m = ptr.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // int lcs = f(str, ptr, n, m, dp);

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str[i - 1] == ptr[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs = dp[n][m];

    return n - lcs + m - lcs;
}