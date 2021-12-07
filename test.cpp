#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int val[N];
int cnt;

void dfs(int vtx, int par, long long target, long long curr_sum, int curr_cnt)
{
   if (par != 0)
   {
      curr_sum += val[vtx];
      curr_cnt++;
   }
   if (curr_sum >= target)
   {
      cnt = min(cnt, curr_cnt);
      return;
   }
   for (auto child : g[vtx])
   {
      if (child == par)
         continue;
      dfs(child, vtx, target, curr_sum, curr_cnt);
   }
}
int main()
{
   int n, q;
   cin >> n >> q;

   for (int i = 1; i <= n; i++)
      cin >> val[i];

   for (int i = 0; i < n - 1; i++)
   {
      int v1, v2;
      cin >> v1 >> v2;
      g[v1].push_back(v2);
      g[v2].push_back(v1);
   }

   while (q--)
   {
      int x;
      long long k;
      cin >> x >> k;

      cnt = INT_MAX;
      int curr_cnt = 1;
      long long curr_sum = val[x];
      dfs(x, 0, k, curr_sum, curr_cnt);
      if (cnt == INT_MAX)
         cout << -1 << endl;
      else
         cout << cnt << endl;
   }

   return 0;
}