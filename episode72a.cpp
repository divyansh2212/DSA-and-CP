// LeetCode Flood Fill
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &image, int initialColor, int newColor)
{
    int m = image.size();
    int n = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (i >= m || j >= n)
        return;
    if (image[i][j] != initialColor)
        return;

    image[i][j] = newColor;
    dfs(i + 1, j, image, initialColor, newColor);
    dfs(i - 1, j, image, initialColor, newColor);
    dfs(i, j + 1, image, initialColor, newColor);
    dfs(i, j - 1, image, initialColor, newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int initialColor = image[sr][sc];
    if (initialColor != newColor)
        dfs(sr, sc, image, initialColor, newColor);
    return image;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> newGrid = floodFill(arr, 1, 1, 2);

    return 0;
}