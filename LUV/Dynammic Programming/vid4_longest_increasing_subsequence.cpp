#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

int lis(vector<int> &a, int idx)
{
    if (dp[idx] != -1)
        return dp[idx];
    int ans = 1;

    for (int i = 0; i < idx; i++)
    {
        if (a[i] < a[idx])
            ans = max(ans, lis(a, i) + 1);
    }

    return dp[idx] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, lis(a, i));

    cout << ans;
    return 0;
}