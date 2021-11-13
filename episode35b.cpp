#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    // auto it = lower_bound(s.begin(), s.end(), 5); // O(n)
    auto it = s.lower_bound(10); // O(log(n))
    if (it == s.end())
    {
        cout << "Not found!" << endl;
    }
    else
        cout << *it << endl;
    return 0;
}