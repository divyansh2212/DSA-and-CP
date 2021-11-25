#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long binExp(long long a, long long b)
{
   long long ans = 1;
   while (b > 0)
   {
      if (b & 1)
         ans = (ans * a) % M;
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
      int cnt;
      cin >> cnt;
      vector<long long> numbers(cnt);
      vector<long long> powers(cnt);
      vector<long long> gps(cnt);
      for (int i = 0; i < cnt; i++)
         cin >> numbers[i];

      for (int i = 0; i < cnt; i++)
         cin >> powers[i];

      for (int i = 0; i < cnt; i++)
      {
         long long numera = (numbers[i] * (binExp(numbers[i], powers[i]) - 1)) % M;
         long long deno = numbers[i] - 1;
         long long ele = (numera * binExp(deno, M - 2)) % M;
         gps[i] = ele;
      }

         long long ans = 1;
         for (long long i = 0; i < gps.size(); i++)
         {
            ans = (ans * gps[i]) % M;
         }
         cout << ans << endl;
   }

   return 0;
}