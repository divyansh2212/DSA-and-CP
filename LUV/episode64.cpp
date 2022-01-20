#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int hp[N];
bool canremove[N];
int hsh[N];
vector<int> distinctpfs(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        int pf = hp[x];
        while (x % pf == 0)
        {
            x = x / pf;
        }
        ans.push_back(pf);
    }
    return ans;
}
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j = j + i)
            {
                hp[j] = i;
            }
        }
    }

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        hsh[y] = 1;
    }

    for (int i = 2; i < N; i++)
    {
        if (hsh[i] == 1)
        {
            for (long long j = i; j < N; j = j * i)
            {
                canremove[j] = 1;
            }
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        vector<int> pfs = distinctpfs(x);
        bool flag = false;
        for (int i = 0; i < pfs.size(); i++)
        {
            for (int j = i; j < pfs.size(); j++)
            {
                int product = pfs[i] * pfs[j];
                if (i == j && x % product != 0)
                    continue;
                int toremove = x / product;
                if (canremove[toremove] == 1 || toremove == 1)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}