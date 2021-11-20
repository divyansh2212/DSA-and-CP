#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int fact[N];
int binExp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b = (b >> 1);
    }
    return ans;
}
int main()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = (fact[n] * 1LL * fact[k]) % M;
        int den = (fact[k - n] * 1LL * fact[n]) % M;
        ans = (ans * 1LL * binExp(den, M - 2)) % M;
        cout << ans << endl;
    }
    return 0;
}