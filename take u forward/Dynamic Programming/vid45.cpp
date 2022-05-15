// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// LONGEST DIVISIBLE SUBSEQUENCE

vector<int> divisibleSet(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size(), maxAns = 1, lastIdx = 0;

    vector<int> dp(n, 1);
    vector<int> hash(n);

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0)
            {
                if (dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
        }
        if (dp[i] > maxAns)
            maxAns = dp[i], lastIdx = i;
    }

    vector<int> ans;
    ans.push_back(arr[lastIdx]);
    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        ans.push_back(arr[lastIdx]);
    }
    return ans;
}