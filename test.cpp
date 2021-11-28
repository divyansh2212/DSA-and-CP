#include <bits/stdc++.h>
using namespace std;
int invertBits(int n, int bits)
{
   int number = 0;
   for (int i = 0; i < bits; i++)
   {
      if ((n & (1 << i)) == 0)
      {
         number = (number | (1 << i));
      }
   }
   return number;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      long a, b, n;
      cin >> a >> b >> n;
      int maxmBits = max((int)log2(a) + 1, (int)log2(b) + 1);
      long nthxor, nthxnor, ans;
      nthxor = (a ^ b);
      nthxnor = invertBits(nthxor, maxmBits);
      if (n % 3 == 1 || n == 1)
         cout << a << endl;
      else if (n % 3 == 2 || n == 2)
         cout << b << endl;
      else if (n % 3 == 0)
         cout << max(nthxnor, nthxor) << endl;
   }

   return 0;
}