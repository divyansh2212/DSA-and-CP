#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool canWePlace(int d, int cows, int location[], int n)
{
    int lastpos = -1;
    for (int i = 0; i < n; i++)
    {
        if (lastpos == -1)
        {
            lastpos = location[0];
            cows--;
        }
        else if (location[i] - lastpos >= d)
        {
            lastpos = location[i];
            cows--;
        }
        if (cows == 0)
            break;
    }
    return cows == 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int location[N];
        for (int i = 0; i < n; i++)
            cin >> location[i];
        //  T T T T T T T T F F F F F F F
        sort(location, location + n);
        int lo = 0, hi = 1e9, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (canWePlace(mid, c, location, n) == true)
                lo = mid;
            
            else if (canWePlace(mid, c, location, n) == false)
                hi = mid - 1;
            
        }
        if (canWePlace(hi, c, location, n))
            cout << hi << endl;
        
        else
            cout << lo << endl;
    }

    return 0;
}