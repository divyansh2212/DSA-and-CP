// Binary Exponentiation using Iterative Method
#include <bits/stdc++.h>
using namespace std;
int BinExpIter(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        
        a = a * a;
        b = (b >> 1);
    }
    return ans;
}
int main()
{
    cout << BinExpIter(3, 4) << endl;
    return 0;
}