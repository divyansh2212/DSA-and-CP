#include <bits/stdc++.h>
using namespace std;

void printName(string s, int i)
{
    if (i == 5)
        return;
    cout << s << endl;
    printName(s, ++i);
}

void printNto1(int i, int n)
{
    if (i > n)
        return;
    printNto1(i + 1, n);
    cout << i << endl;
}

int main()
{
    // printName("Divyansh", 0);
    printNto1(1, 5);
    return 0;
}