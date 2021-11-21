#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

long long binExp(long long a, int b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % M;
        a = (a * a) % M;
        b = (b >> 1);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    long long fx = 1;
    int gx;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        fx = (fx * x) % M;
        if (i == 0)
            gx = x;
        if (i > 0)
        {
            gx = __gcd(gx, x);
        }
    }
    cout << binExp(fx, gx);
    return 0;
}