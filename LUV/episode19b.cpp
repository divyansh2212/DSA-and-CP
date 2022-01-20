// Merge Sort
// Time Complexity --- O(N.log(N))
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void merge(int l, int r, int mid)
{
    int l_size = mid - l + 1;
    int L[l_size + 1];
    int r_size = r - (mid + 1) + 1;
    int R[r_size + 1];

    for (int i = 0; i < l_size; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < r_size; i++)
    {
        R[i] = a[mid + 1 + i];
    }

    L[l_size] = R[r_size] = INT_MAX;

    int l_idx = 0, r_idx = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_idx] <= R[r_idx])
        {
            a[i] = L[l_idx];
            l_idx++;
        }
        else
        {
            a[i] = R[r_idx];
            r_idx++;
        }
    }
}
void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}