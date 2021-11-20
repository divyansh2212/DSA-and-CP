#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int fact[N];
const int m = 1e9 + 7;
int binExp(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * 1LL * a;
        a = a * 1LL * a;
        b = (b >> 1);
    }
    return ans;
}
int main()
{
    // There are n children and r toffees. r < n
    // count the number of ways to distribute r toffees among n children
    // such that each child gets 1 toffee atmost
    // no of queries, q < 10^5
    // r < n < 10^6
    // ans is (nCr) % m
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * 1LL * i) % m;

    int q;
    cin >> q;
    while (q--)
    {
        int n, r;
        cin >> n >> r;
        int ans = 1;
        int numera = fact[n];
        int deno = (fact[n - r] * 1LL * fact[r]) % m;
        int inversedeno = binExp(deno, m - 2, m);
        ans = numera * inversedeno;
        cout << ans << endl;
    }

    return 0;
}