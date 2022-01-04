#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> l(n), r(n);
        bool mark[n+1][n+1] = {false};
        for (int i = 0; i < n; ++i)
        {
            cin >> l[i] >> r[i];
            mark[l[i]][r[i]] = true;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int d = l[i]; d <= r[i]; ++d)
            {
                if((mark[l[i]][d-1] || d == l[i]) && (mark[d+1][r[i]] || d == r[i]))
                {
                    cout << l[i] << " " << r[i] << " " << d << endl;
                    break;
                }
            }
        }
    }
    return 0;
}