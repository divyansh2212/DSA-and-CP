#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> prefix_sum(n);
    prefix_sum[0] = arr[0];

    for(int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i-1] + arr[i];

    int coins = 0;
    int sum = 0;
    int prev;
    for(int i = n - 1; i >= 1; i--)
    {
        prev = prefix_sum[i-1];
        sum += arr[i];
        coins++;
        if(sum > prefix_sum[i-1])
            break;
    }
    if(sum <= prev)
        coins++;
    cout << coins;
    return 0;
}