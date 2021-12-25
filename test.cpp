#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, c01, c10;
        cin >> n >> c01 >> c10;
        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        int cost = 0;
        if(arr[0] == arr[1])
        {
            if(arr[0] == 0)
                cost += c01;
            else
                cost += c10;
            arr[0] = !arr[1];
        }
        
        for (int i = 1; i < n; i = i+2)
        {
            if(arr[i] == arr[i-1])
            {
                if(i + 1 < n && arr[i] == arr[i+1])
                {
                    if(arr[i] == 0)
                        cost += c01;
                    if(arr[i] == 1)
                        cost += c10;
                    arr[i] = !arr[i];
                }
                else
                {
                    if(arr[i] == 1)
                        cost += c10;
                    if(arr[i] == 0)
                        cost += c01;
                    arr[i] = !arr[i];
                }
            }
            else if(i+1 < n && arr[i] == arr[i+1])
            {
                
                    if(arr[i+1] == 0)
                        cost += c01;
                    if(arr[i+1] == 1)
                        cost += c10;
                    arr[i+1] = !arr[i+1];
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
        cout << cost << endl;
    }
    return 0;
}