#include <bits/stdc++.h>
using namespace std;
#define ll long long

int func(vector<vector<int>> &points, int lastTask, int day, vector<vector<int>> &dp)
{
    if (day < 0)
        return 0;
    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];
    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if (task != lastTask)
            maxi = max(maxi, points[day][task] + func(points, task, day - 1, dp));
    }
    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    //     return func(points, 3, n - 1, dp);
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day - 1][task]);
            }
        }
    }
    return dp[n - 1][3];
}