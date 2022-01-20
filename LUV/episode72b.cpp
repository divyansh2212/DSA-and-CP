#include <bits/stdc++.h>
using namespace std;
const int N = 300;
bool visited[N][N];

void dfs(int i, int j, vector<vector<char>> &grid)
{
    if (i < 0 || j < 0)
        return;
    if (i >= grid.size() || j >= grid[0].size())
        return;
    if (visited[i][j] || grid[i][j] == '0')
        return;

    visited[i][j] = true;

    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}
int numIslands(vector<vector<char>> &grid)
{
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (visited[i][j])
                continue;
            if (grid[i][j] == '1')
            {
                dfs(i, j, grid);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{

    return 0;
}