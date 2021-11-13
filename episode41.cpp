#include <iostream>
#include <vector>
using namespace std;
int upper_bound(vector<int> &v, int element)
{
    int lower = 0, upper = v.size() - 1, mid;
    while (upper - lower > 1)
    {
        mid = lower + (upper - lower) / 2;
        if (v[mid] <= element)
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid;
        }
    }
    if (v[lower] > element)
    {
        return lower;
    }
    if (v[upper] > element)
    {
        return upper;
    }

    return -1;
}
int lower_bound(vector<int> &v, int element)
{
    int lower = 0, upper = v.size() - 1, mid;
    while (upper - lower > 1)
    {
        mid = lower + (upper - lower) / 2;
        if (v[mid] < element)
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid;
        }
    }
    if (v[lower] >= element)
    {
        return lower;
    }
    if (v[upper] >= element)
    {
        return upper;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int element;
    cin >> element;
    int lb = lower_bound(v, element);
    int ub = upper_bound(v, element);
    cout << lb << endl
         << ub << endl;
    return 0;
}