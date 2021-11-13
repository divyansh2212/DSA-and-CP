#include <bits/stdc++.h>
using namespace std;
void printBinary(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}
int main()
{
    //   Consider this problem:
    //   There are N≤5000 workers.
    //   Each worker is available during some days of this month (which has 30 days).
    //   For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability.
    //   You need to assign an important project to two workers but they will be able to work on the project only when they are both available.
    //   Find two workers that are best for the job — maximize the number of days when both these workers are available.
    int n;
    cin >> n;
    vector<int> masks(5, 0);
    for (int i = 0; i < n; i++)
    {
        int num_days;
        cin >> num_days;
        int mask = 0;
        for (int j = 0; j < num_days; j++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int intersection = (masks[i] & masks[j]);
            int common_days = __builtin_popcount(intersection);
            if (common_days > ans)
            {
                ans = common_days;
            }
        }
    }

    cout << ans;
    return 0;
}