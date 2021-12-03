#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      vector<int> hsh(N, 0);
      int n;
      cin >> n;
      bool flag = false;
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
         int x;
         cin >> x;
         hsh[x]++;
         if (hsh[x] == 2)
            flag = true;
         //  if (hsh[x] > 1)
         cnt = max(cnt, hsh[x] - 1);
      }
      if (n == 1)
      {
         cout << 0 << endl;
         continue;
      }
      else if (flag == false)
      {
         cout << -1 << endl;
         continue;
      }
      int cnt2 = 0;
      for (int i = 0; i < n; i++)
      {
         if (hsh[i])
            cnt2++;
      }
      if (cnt2 == 1)
         cnt++;

      cout << n - cnt << endl;
   }
   return 0;
}