#include <bits/stdc++.h>
using namespace std;
// O (n * 2^n)
vector<vector<int>> subsetsgenerate(vector<int> &v)
{
    vector<vector<int>> subsets;
    int n = v.size();
    int subsets_cnt = (1 << n);
    for (int i = 0; i < subsets_cnt; i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(v[j]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    auto ans = subsetsgenerate(v);
    for (auto subset : ans)
    {
        for (auto ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}