#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = func(n - 1, dp) + func(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;

    // vector<int> dp(n + 1, -1);
    // cout << func(n, dp);


    // Bottom up approach
    int prev = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    return 0;
}