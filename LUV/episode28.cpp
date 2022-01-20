#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        multiset<long long> s;
        for (int i = 0; i < n; i++)
        {
            long long candy_cnt;
            cin >> candy_cnt;
            s.insert(candy_cnt);
        }
        long long total = 0;
        while (k--)
        {
            auto it = --(s.end());
            long long last_bag = *it;
            total += last_bag;
            s.erase(it);
            s.insert(last_bag / 2);
        }
        cout << total << endl;
    }

    return 0;
}