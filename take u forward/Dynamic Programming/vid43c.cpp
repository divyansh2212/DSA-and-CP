// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Printing LIS
int main()
{
    vector<int> arr = {5, 4, 11, 1, 16, 8};
    int n = arr.size(), lastIndex = 0;

    vector<int> dp(n, 1);
    vector<int> hash(n);

    int maxi = 0;

    for (int idx = 0; idx < n; idx++)
    {
        hash[idx] = idx;
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[prev] < arr[idx] && dp[prev] + 1 > dp[idx])
            {
                dp[idx] = dp[prev] + 1;
                hash[idx] = prev;
            }
        }

        if (dp[idx] > maxi)
        {
            maxi = dp[idx];
            lastIndex = idx;
        }
    }

    vector<int> ans;

    ans.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(), ans.end());

    cout << maxi << endl;

    for (auto &it : ans)
        cout << it << " ";

    return 0;
}