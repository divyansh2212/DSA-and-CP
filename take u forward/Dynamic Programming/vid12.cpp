#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    return 0;
}

int func(int i, int j, vector<vector<int>> &matrix)
{
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        return 0;
    if (i == matrix.size() - 1)
        return matrix[i][j];

    int maxmProfit = 0;
    maxmProfit = max(maxmProfit, func(i + 1, j, matrix) + matrix[i][j]);
    maxmProfit = max(maxmProfit, func(i + 1, j - 1, matrix) + matrix[i][j]);
    maxmProfit = max(maxmProfit, func(i + 1, j + 1, matrix) + matrix[i][j]);

    return maxmProfit;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int maxmProfit = 0;
    for (int j = 0; j < matrix[0].size(); j++)
    {
        maxmProfit = max(maxmProfit, func(0, j, matrix));
    }
    return maxmProfit;
}