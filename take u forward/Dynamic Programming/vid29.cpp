#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int f(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 || idx2 < 0)
            return 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (s[idx1] == t[idx2])
            return dp[idx1][idx2] = 1 + f(s, t, idx1 - 1, idx2 - 1, dp);
        else
            return dp[idx1][idx2] = max(f(s, t, idx1 - 1, idx2, dp), f(s, t, idx1, idx2 - 1, dp));
    }

    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return f(s, t, s.length() - 1, t.length() - 1, dp);
    }
};