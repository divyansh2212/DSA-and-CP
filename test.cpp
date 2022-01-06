#include<bits/stdc++.h>
using namespace std;
// const int M = 1e9 + 7;
const int N = 1e6 + 10;
long long lcm(int x, int y)
{
    return ((x*1LL*y) / __gcd(x, y));
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        bool flag = false;
        for (int i = l; i <= r / 2; ++i)
        {
            int j = 2 * i;
            if(j <= r && lcm(i, j) <= r)
            {
                flag = true;
                cout << i << " " << j << endl;
                break;
            }
        }
        if(flag == false)
            cout << -1 << " " << -1 << endl;
    }
    return 0;
}