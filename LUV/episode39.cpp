// Subsets Generation
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void generateSubsets(int i, vector<int> subset, vector<int> &nums)
{
    if (i == nums.size())
    {
        ans.push_back(subset);
        return;
    }

    generateSubsets(i + 1, subset, nums);

    subset.push_back(nums[i]);
    generateSubsets(i + 1, subset, nums);
    subset.pop_back();
}
int main()
{
    int n;
    cin >> n;
    vector<int> parentSet;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        parentSet.push_back(x);
    }
    vector<int> subset;
    generateSubsets(0, subset, parentSet);

    for (auto &subsets : ans)
    {
        for (auto &ele : subsets)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}