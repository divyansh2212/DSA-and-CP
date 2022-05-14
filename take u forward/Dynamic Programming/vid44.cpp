// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;

    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (temp.back() < arr[i])
            temp.push_back(arr[i]);

        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    return temp.size();
}
