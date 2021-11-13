#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Time Complexity : O(1)
    unordered_map<int, string> m;
    m[1] = "abc";
    m[3] = "ghi";
    m[2] = "def";
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}