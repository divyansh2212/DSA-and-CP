#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binExp(int a, int b)
{
   int ans = 1;
   while (b > 0)
   {
      if (b & 1)
         ans = (ans * 1LL * a) % M;
      a = (a * 1LL * a) % M;
      b = (b >> 1);
   }
   return ans;
}
int main()
{
   long long sum = 0;
   int faculties;
   cin >> faculties;
   while (faculties--)
   {
      int courses;
      cin >> courses;
      sum = sum + binExp(2, courses) - 1;
      sum = sum % M;
      while (courses--)
      {
         int points;
         cin >> points;
      }
   }
   cout << sum;
   return 0;
}