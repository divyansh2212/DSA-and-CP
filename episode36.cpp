#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min = *min_element(v.begin(), v.end());
    cout << min << endl;
    int max = *max_element(v.begin(), v.end());
    cout << max << endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
    int cnt = count(v.begin(), v.end(), 2);
    cout << cnt << endl;
    auto it = find(v.begin(), v.end(), 2);
    if (it != v.end())
    {
        cout << *it << endl;
    }
    else
        cout << "Element not found!" << endl;

    reverse(v.begin(), v.end());
    return 0;
}