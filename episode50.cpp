#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Swap 2 nos using XOR
    int a = 4, b = 6;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b;
    return 0;
}