#include <bits/stdc++.h>
using namespace std;
int perimeter = 0;
void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, bool flag)
{
   if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
      return;
   if (grid[i][j] == 0 || visited[i][j])
      return;

   visited[i][j] = true;
   if (flag)
      perimeter -= 2;

   dfs(i + 1, j, grid, visited, true);
   dfs(i - 1, j, grid, visited, true);
   dfs(i, j + 1, grid, visited, true);
   dfs(i, j - 1, grid, visited, true);
}
int islandPerimeter(vector<vector<int>> &grid)
{
   vector<bool> unda(100, false);
   vector<vector<bool>> visited(100, unda);

   for (int i = 0; i < grid.size(); i++)
   {
      for (int j = 0; j < grid[i].size(); j++)
      {
         if (visited[i][j])
            continue;
         dfs(i, j, grid, visited, false);
      }
   }
   for (int i = 0; i < visited.size(); i++)
   {
      for (int j = 0; j < visited[i].size(); j++)
      {
         if (visited[i][j])
            perimeter += 4;
      }
   }

   return perimeter;
}
int main()
{

   return 0;
}