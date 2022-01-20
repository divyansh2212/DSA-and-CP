#include <bits/stdc++.h>
using namespace std;
void printBinary(int n)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}
int main()
{
    int n = 12;
    printBinary(12);
    int i = 2;
    // To check if set bit or not
    if (((1 << i) & n) != 0)
    {
        cout << "SetBit\n";
    }
    else
        cout << "Not a SetBit\n";

    // To set a ith bit
    i = 1;
    int x = (1 << i) | n;
    printBinary(x);

    // To unset a ith bit
    i = 3;
    int y = ~(1 << i) & n;
    printBinary(y);

    // Toggle a bit
    i = 7;
    int z = (1 << i) ^ n;
    printBinary(z);

    // Count number of set bits
    int cnt = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (((1 << i) & n) != 0)
            cnt++;
    }
    cout << cnt << endl;

    cout << __builtin_popcount(19) << endl;
    cout << __builtin_popcountll((1LL << 35) - 1) << endl;
    return 0;
}