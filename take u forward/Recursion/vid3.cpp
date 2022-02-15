#include <bits/stdc++.h>
using namespace std;

int sumOfFirstN(int n)
{
    if (n == 0)
        return 0;
    return n + sumOfFirstN(n - 1);
}

int main()
{
    cout << sumOfFirstN(5);
    return 0;
}