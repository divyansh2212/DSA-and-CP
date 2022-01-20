#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    auto it = lower_bound(a.begin(), a.end(), 10); // O(log(n))
    if (it == a.end())
    {
        cout << "Not found!" << endl;
    }
    else
        cout << *it << endl;
    return 0;
}