// Large Exponentiation using Binary Multiplication
#include <bits/stdc++.h>
using namespace std;
const long long M = 1e18 + 7;
// a, M <= 1e18

long long binMulti(long long a, long long b)
{
    long long ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = ((ans + a) % M);
        }
        a = (a + a) % M;
        b = (b >> 1);
    }
    return ans;
}
long long binExp(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = binMulti(ans, a); //(ans * a) % M;
        }
        a = binMulti(a, a); //(a * a) % M;
        b = (b >> 1);
    }
    return ans;
}

int main()
{
    cout << binExp(4, 3);
    return 0;
}