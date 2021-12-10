#include <bits/stdc++.h>
using namespace std;
const int N = 45e4 + 10;
vector<int> p(N);
vector<int> val(N);

void dfs(int vtx, int par, vector<int> g[N], vector<unordered_set<int>> &valarray)
{
   p[vtx] = par;
   valarray[vtx].insert(val[vtx]);
   for (auto child : g[vtx])
   {
      if (child == par)
         continue;
      dfs(child, vtx, g, valarray);
      valarray[vtx].insert(val[child]);
   }
}
vector<int> path(int node)
{
   vector<int> ans;
   while (node != -1)
   {
      ans.push_back(node);
      node = p[node];
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, q, r;
      cin >> n >> q >> r;
      vector<int> g[n];
      p.clear();
      val.clear();

      for (int i = 0; i < n; i++)
         cin >> val[i];

      for (int i = 0; i < n - 1; i++)
      {
         int x, y;
         cin >> x >> y;
         g[x].push_back(y);
         g[y].push_back(x);
      }

      vector<unordered_set<int>> valarray(n);
      dfs(r, -1, g, valarray);

      while (q--)
      {
         int x, y;
         cin >> x >> y;
         vector<int> path_x = path(x);
         vector<int> path_y = path(y);
         int min_ln = min(path_x.size(), path_y.size());
         int lca = -1;
         for (int i = 0; i < min_ln; i++)
         {
            if (path_x[i] == path_y[i])
               lca = path_x[i];
            else
               break;
         }
         cout << valarray[lca].size() << endl;
      }
   }

   return 0;
}