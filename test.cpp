#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        if(n % 4 == 0)
        {
            cout << "1 " << n << " " << endl;
            continue;
        }
        if(n % 4 == 1)
        {
            cout << "1 1 " << endl;
            continue;
        }
        if(n % 4 == 2)
        {
            cout << "2 " << n << " 1 " << endl;
            continue;
        }
        if(n % 4 == 3)
            cout << 0 << endl;
    }

    return 0;
}