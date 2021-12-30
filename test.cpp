#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        long long p = 1;
        long long ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if(k & (1 << i))
            {
                ans = (ans + p) % M;
            }
            p = (p * n) % M;
        }
        cout << ans << endl;
    }

    return 0;
}