#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
bool visited[N];
int edge_cnt;
vector<vector<int>> ccs;
vector<int> current_cc;

void dfs(int vtx)
{
   current_cc.push_back(vtx);
   visited[vtx] = true;
   for (auto child : g[vtx])
   {
      if (visited[child])
         continue;
      edge_cnt++;
      dfs(child);
   }
}
int main()
{
   int n, m;
   cin >> m >> n;
   if (n == 0)
   {
      cout << "0/1";
      return 0;
   }
   for (int i = 0; i < m; i++)
   {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
   }
   if (n >= m)
   {
      cout << ">1";
      return 0;
   }
   if (m == 0)
   {
      cout << "0/1";
      return 0;
   }

   double ratio;
   int v_cnt;
   vector<double> ratios;
   vector<int> edges;
   for (int i = 1; i <= n; i++)
   {
      if (visited[i])
         continue;
      edge_cnt = 0;
      current_cc.clear();
      dfs(i);
      v_cnt = current_cc.size();
      ratio = ((1.0 * edge_cnt) / v_cnt);
      edges.push_back(edge_cnt);
      ratios.push_back(ratio);
      ccs.push_back(current_cc);
   }

   int big_idx;
   ratio = -1;
   for (int i = 0; i < ratios.size(); i++)
   {
      if (ratio < ratios[i])
         ratio = ratios[i], big_idx = i;
   }
   
   if (ratio == 1)
      cout << "1/1";

   else if (ratio > 1)
      cout << ">1";

   else
   {
      edge_cnt = edges[big_idx];
      v_cnt = ccs[big_idx].size();
      cout << edge_cnt << "/" << v_cnt;
   }

   return 0;
}