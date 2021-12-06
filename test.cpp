#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int val[N];
int curr_ans1 = 0;
int curr_ans2 = 0;

void dfs1(int vtx, int par = 0)
{
   for (auto child : g[vtx])
   {
      if (child == par)
         continue;

      if (val[child] == 1)
      {
         if (val[par] == 0 && par != 0)
         {
            if (child < vtx)
               curr_ans1++;
            else if (child > vtx)
               curr_ans2++;
         }
         continue;
      }
      dfs1(child, vtx);

      if (child < vtx)
         curr_ans1++;
      else if (child > vtx)
         curr_ans2++;
   }
}
int main()
{
   int n;
   cin >> n;
   for (int i = 0; i < n - 1; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
   }

   for (int i = 1; i <= n; i++)
      cin >> val[i];

   int ans = 0;
   for (int i = 1; i <= n; i++)
   {

      if (val[i] == 1)
      {
         curr_ans1 = 1;
         curr_ans2 = 1;
         dfs1(i, 0);
      }

      ans = max(ans, max(curr_ans2, curr_ans1));
   }
   cout << ans;
   return 0;
}