#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int type, t, x, k;
        cin >> type >> x >> t;
        if(type == 1)
        {
            // cin >> x >> t;
            m[t] = x;
        }
        else if(type == 2)
        {
            // cin >> k >> t;
            long long sum = 0;
            for(int i = t; i > t - x; i--)
            {
                if(m[t])
                    sum += m[t];
            }
            cout << sum << endl;
        }
    }

    return 0;
}