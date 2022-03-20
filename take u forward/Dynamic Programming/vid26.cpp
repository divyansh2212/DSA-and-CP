#include <bits/stdc++.h>
using namespace std;

int f(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 1 + f(s, t, i - 1, j - 1, dp);

    return dp[i][j] = max(f(s, t, i - 1, j, dp), f(s, t, i, j - 1, dp));
}

int lcs(string s, string t)
{
        int n = s.length(), m = t.length();
        //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // 	return f(s, t, n, m, dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= m; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    return dp[n][m];
}

int lcs(string s, string t)
{
    int n = s.length(), m = t.length();

    vector<int> prev(m + 1, 0);

    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        prev[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}