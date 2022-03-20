#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Minimum insertions to make a string palindrome

int minInsertion(string &s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs = dp[n][n];
    return n - lcs;
}