#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int time = 240 - k;

    long long arr[n+1];
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = 5*1LL*i;
        sum += arr[i];
        if(sum > time)
        {
            cout << i - 1;
            return 0;
        }
    }
    cout << n;
    return 0;
}