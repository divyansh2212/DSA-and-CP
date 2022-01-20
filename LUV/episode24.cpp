#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for (int value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    // By reference
    for (auto &value : v)
    {
        cout << value << " ";
    }
    cout << endl;

    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}};
    for (pair<int, int> &val : v_p)
    {
        cout << val.first << " " << val.second << endl;
    } cout << endl;
    for (auto &val : v_p)
    {
        cout << val.first << " " << val.second << endl;
    }
    return 0;
}