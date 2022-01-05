#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int multiples_cnt[N];
int hsh[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            multiples_cnt[i] += hsh[j];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        long ans = multiples_cnt[p] + multiples_cnt[q];
        long long lcmpq = (p * 1LL * q) / __gcd(p, q);
        if (lcmpq < N)
            ans = ans - multiples_cnt[lcmpq];
        cout << ans << endl;
    }

    return 0;
}