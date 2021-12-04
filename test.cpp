#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool check(string s, int lo, int hi)
{
   int cnt0 = 0, cnt1 = 0;
   for (int i = lo; i <= hi; i++)
   {
      if (s[i] == '0')
         cnt0++;
      if (s[i] == '1')
         cnt1++;
   }
   if (cnt0 > cnt1)
   {
      if (ans > hi - lo + 1)
         ans = hi - lo + 1;
      return true;
   }
   return false;
}
int main()
{
   int n;
   cin >> n;
   string s;
   cin >> s;

   int hi = n - 1, lo = 0, mid;
   while (hi - lo > 2)
   {
      if (check(s, lo, hi))
      {
         cout << ans;
         return 0;
      }
      if (s[hi] == '1')
         hi--;
      else
         lo++;
   }
   return 0;
}