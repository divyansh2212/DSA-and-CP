#include <bits/stdc++.h>
using namespace std;

bool checking(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1])
            return false;
    }
    return true;
}

int main()
{

    int n;
    cin >> n;
    int a[n], b[n];
    int mn = INT_MAX;

    for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
        }

    for (int i = 0; i < n; ++i)
        cin >> b[i];
    

    int cnt = 0; bool flag = false;

    while(flag == false)
    {
        for(int i = 0; i < n; i++)
        {
            if(checking(a, n))
                break;
            if(a[i] > mn)
            {
                a[i] = a[i] - b[i];
                if(a[i] < 0)
                {
                    flag = true;
                    break;
                }
                mn = min(mn, a[i]);
                cnt++;
            }
        }
        if(checking(a, n))
                break;
        if(flag)
            break;
    }
    if(flag)
        cout << -1;
    else
        cout << cnt;


    return 0;
}