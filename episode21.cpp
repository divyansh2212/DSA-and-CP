#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, string> p;
    p = make_pair(3, "abc");
    p = {12, "asdf"};
    p.first = 54;
    //   cout << p.first << " " << p.second << endl;

    int a[] = {1, 2, 3};
    int b[] = {2, 3, 4};
    pair<int, int> p_arr[3];
    p_arr[0] = {1, 2};
    p_arr[1] = {2, 3};
    p_arr[2] = {3, 4};
    swap(p_arr[0], p_arr[2]);
    for (int i = 0; i < 3; i++)
    {
        cout << p_arr[i].first << " " << p_arr[i].second << endl;
    }

    vector<int> v(10, 3);
    vector<int> v2 = v; // O(n)

    return 0;
}