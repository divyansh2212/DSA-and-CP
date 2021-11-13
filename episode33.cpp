#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    // O(n. log(n))
    // IntroSort = QuickSort + HeapSort + InsertionSort
    return 0;
}