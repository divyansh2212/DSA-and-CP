#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v.begin();
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}};
    vector<pair<int, int>>::iterator it1;

    // First Method
    for (it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout << (*it1).first << " " << (*it1).second << endl;
    }

    // Second Method
    for (it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout << it1->first << " " << it1->second << endl;
    }
    return 0;
}