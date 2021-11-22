#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, l, r, k;
    cin >> n >> m;
    cin >> l >> r;
    cin >> k;
    long long NmodM = (n % m);
    vector<long long> arr;

    for (long long i = l; i <= r; i++)
    {
        if ((n % i) == NmodM && i != m)
            arr.push_back(i);
    }
    if (arr.size() > k)
        cout << arr.size() << endl
             << -1 << endl;
    else
    {
        cout << arr.size() << endl;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}