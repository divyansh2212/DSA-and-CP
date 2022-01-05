#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
// Modular Multiplicative Inverse
int binExp(int a, int b, int n)
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
    // (a / b) % m = ((a % m) * (b^(-1) % m)) % m
    // For finding b^(-1)
    // b and m must be co-prime && b is not a multiple of m
    // m is prime here
    // then, b^(m-2) % m = b^(-1)
    int a = 2;
    // Inverse of a :
    cout << binExp(a, m - 2, m);
    return 0;
}