#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    int x;
    cin >> x;
    int lower = 0, upper = n - 1;
    int mid;
    while (upper - lower > 1)
    {
        mid = (upper + lower) / 2;
        if (v[mid] < x)
            lower = mid + 1;
        else
            upper = mid;
    }

    if (v[lower] == x)
        cout << lower << endl;

    else if (v[upper] == x)
        cout << upper << endl;

    else
        cout << "Not found!" << endl;
    
    return 0;
}