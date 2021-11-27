#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int squaresum(int n)
{
   if (n % 2 != 0)
      return (((n * ((n + 1) / 2)) % M) * (((2 * n + 1) / 3) % M)) % M;
   return ((((n / 2) * (n + 1)) % M) * (((2 * n + 1) / 3) % M)) % M;
}
int binExp(long long a, int b)
{
   int ans = 1;
   while (b > 0)
   {
      if (b & 1)
         ans = (ans * 1LL * a) % M;
      a = (a * a) % M;
      b = (b >> 1);
   }
   return ans;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      long long maxm = 0, minm;

      long long no_match = (n * 1LL * (n - 1)) / 2;
      long long remainder = no_match % n;
      long long first_term = (remainder * binExp(remainder, 2)) % M;
      long long second_term = ((n - remainder) * binExp(no_match / n, 2)) % M;
      minm = (first_term + second_term) % M;

      maxm = squaresum(n-1);
      cout << minm << " " << maxm << endl;
   }

   return 0;
}