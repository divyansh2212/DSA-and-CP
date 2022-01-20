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
    // Uppercase to lowercase and viceversa
    char C = 'C';
    char c = C | (1 << 5);
    cout << c << endl;
    cout << char('O' | ' ') << endl;
    char d = 'd';
    char D = d & ~(1 << 5);
    cout << D << endl;
    cout << char('e' & '_') << endl;
    int n = 59;
    // odd even check
    if (n & 1 != 0)
        cout << "odd\n";
    else
        cout << "even\n";

    // Multiply divide by 2
    int prod = n << 1;
    cout << prod << endl;
    int div = n >> 1;
    cout << div << endl;

    // Power of 2 check
    if ((n & (n - 1)) == 0)
        cout << "Power of 2\n";
    else
        cout << "Not a power of 2\n";

    // Clear LSB till ith bit
    printBinary(n);
    int i = 3;
    int x = (n & ~((1 << (i + 1)) - 1));
    printBinary(x);

    // Clear MSBs till ith bit
    i = 3;
    x = (n & ((1 << (i + 1)) - 1));
    printBinary(x);
    return 0;
}