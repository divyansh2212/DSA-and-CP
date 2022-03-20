#include <bits/stdc++.h>
using namespace std;
#define ll long long

int lcs(string &s, string &t)
{
    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 0; i < m + 1; i++)
        dp[0][i] = 0;

    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}