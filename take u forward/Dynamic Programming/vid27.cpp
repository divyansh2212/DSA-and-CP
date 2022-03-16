#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(string s, string t, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 == 0 || idx2 == 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    if (s[idx1 - 1] == t[idx2 - 1])
        return dp[idx1][idx2] = 1 + f(s, t, idx1 - 1, idx2 - 1, dp);

    return dp[idx1][idx2] = max(f(s, t, idx1 - 1, idx2, dp), f(s, t, idx1, idx2 - 1, dp));
}

string lcs(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int len = f(s, t, n, m, dp);

    string ans = "";
    for (int i = 0; i < len; i++)
        ans.push_back('$');

    int curr_idx = len - 1, i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[curr_idx] = s[i - 1];
            curr_idx--;
            i--, j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
            j--;
        else
            i--;
    }
    return ans;
}