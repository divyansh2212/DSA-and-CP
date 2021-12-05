#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int cnt = 0;

void dfs(int i, int j, vector<vector<char>> &arr)
{
   int m = arr.size() - 1, n = arr[i].size() - 1;
   if (i < 0 || j < 0 || i > m || j > n)
      return;
   if (arr[i][j] != '.')
      return;
   arr[i][j] = '#';
   cnt++;

   dfs(i + 1, j, arr);
   dfs(i - 1, j, arr);
   dfs(i, j + 1, arr);
   dfs(i, j - 1, arr);
}
int main()
{
   int q;
   cin >> q;
   while (q--)
   {
      int n, m;
      cin >> n >> m;
      vector<vector<char>> arr(n, vector<char>(m, 0));

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            cin >> arr[i][j];
         }
      }
      vector<int> ccs;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (arr[i][j] != '.')
               continue;
            cnt = 0;
            dfs(i, j, arr);
            ccs.push_back(cnt);
         }
      }

      cout << ccs.size() << endl;
      for (int i = 0; i < ccs.size(); i++)
      {
         cout << ccs[i] << " ";
      }
      cout << endl;
   }

   return 0;
}