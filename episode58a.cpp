// To check if a number is prime or not
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool is_prime = true;
    if (n == 1)
    {
        is_prime = false;
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            is_prime = false;
    }
    if (is_prime)
        cout << "It is a prime";
    else
        cout << "It is not a prime";
    return 0;
}