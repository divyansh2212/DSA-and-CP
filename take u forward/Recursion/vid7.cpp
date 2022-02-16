#include <bits/stdc++.h>
using namespace std;

int printS(int arr[], int n, int sum, int s, int idx)
{
    if (idx == n)
    {
        if (sum == s)
            return 1;
        return 0;
    }
    s += arr[idx];
    int l = printS(arr, n, sum, s, idx + 1);
    s -= arr[idx];
    int r = printS(arr, n, sum, s, idx + 1);

    return l + r;
}

int main()
{
    int arr[] = {2, 1, 3};  
    int n = 3, sum = 3;

    cout << printS(arr, n, sum, 0, 0);
    return 0;
}