// To create a vector of all prime vectors
// O(sqrt(N))
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> pf;
    // Smallest divisor (not 1) of any number is a prime
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            pf.push_back(i);
            n = n / i;
        }
    }
    if (n > 1)
        pf.push_back(n);
    for (auto primes : pf)
        cout << primes << " ";
    return 0;
}