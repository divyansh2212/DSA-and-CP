#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   vector<int> ans(n, -1);
   vector<int> minimal(n, INT_MAX);

   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = i + 1; j < n; j++)
   //    {
   //       if (__gcd(arr[i], arr[j]) > 1)
   //       {
   //          if (abs(i - j) < minimal[i])
   //          {
   //             ans[i] = j + 1;
   //             minimal[i] = abs(i - j);
   //          }
   //          if (abs(i - j) < minimal[j])
   //          {
   //             ans[j] = i + 1;
   //             minimal[j] = abs(i - j);
   //          }
   //       }
   //    }
   // }
   int lo = 0, hi = n - 1;
   while (hi - lo > 1)
   {
      int mid = (hi + lo) / 2;
      if (__gcd(arr[mid - 1], arr[mid]) > 1 && (mid - 1) >= 0)
      {
         
      }
   }

   for (int i = 0; i < n; i++)
   {
      cout << ans[i] << " ";
   }

   return 0;
}