// Binary Exponentiation using Recursion
#include <bits/stdc++.h>
using namespace std;
int binaryExp(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binaryExp(a, b / 2);
    if (b & 1)
        return a * 1LL * res * res;
    else
        return res * 1LL * res;
}
int main()
{
    cout << binaryExp(3, 4) << endl;
    cout << binaryExp(4, 3);
    return 0;
}