#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int d = abs(arr[0] - arr[1]);
    vector<int> divisors;
    for (int i = 2; i <= d / 2; i++)
    {
        if (d % i == 0)
            divisors.push_back(i);
    }
    divisors.push_back(d);
    vector<int> ans;
    for (int i = 0; i < divisors.size(); i++)
    {
        int l = arr[0] % divisors[i];
        bool flag = true;
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[j] % divisors[i] != l)
                flag = false;
        }
        if (flag)
            ans.push_back(divisors[i]);
    }

    sort(ans.begin(), ans.end());
    for (auto &ele : ans)
    {
        cout << ele << " ";
    }

    return 0;
}