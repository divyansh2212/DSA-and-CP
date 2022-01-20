// -10^9 < int < 10^9
// -10^12 < long int < 10^12
// -10^18 < long long int < 10^18
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a = 1e+5;
    double b = 1e+5;
    double c = a * b;
    cout << c << endl;
    cout << fixed << c << endl;
    cout << fixed << setprecision(0) << c << endl;
    return 0;
}