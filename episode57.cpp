#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0, cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
            sum += i, cnt++;
            if (n / i != i)
            {
                cout << n / i << endl;
                sum += n / i, cnt++;
            }
        }
    }
    cout << sum << " " << cnt << endl;

    // If a number x is given,
    // x = p1^n1 * p2^n2 * p3^n3, where p1, p2 & p3 are primes
    // Then,
    // Number of divisors = (n1 + 1) * (n2 + 1) * (n3 + 1)
    // Sum of divisors = (1 + p1 + p1^2 + p1^3 + ...... + p1^n1) *
    //                   (1 + p2 + p2^2 + p2^3 + ...... + p2^n2) *
    //                   (1 + p3 + p3^2 + p3^3 + ...... + p3^n3)
    //                 = (GP of p1) * (GP of p2) * (GP of p3)
    return 0;
}