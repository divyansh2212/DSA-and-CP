// Square root and pth Root

#include <bits/stdc++.h>
using namespace std;
double eps = 1e-7;
int main()
{
    // Time Complexity : p * log(10^d * x)
    // d = 7, p = 2 here
    double x;
    cin >> x;
    double lo = 1, hi = x, mid;
    while (hi - lo > eps)
    {
        mid = (hi + lo) / 2;

        if (mid * mid < x)
            lo = mid;

        else
            hi = mid;
    }
    cout << setprecision(9) << lo << endl
         << hi << endl;
    //    cout << pow(x, 1.0 / 2) << endl;
    return 0;
}