#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Lambda Functions
    cout << [](int x)
    { return x + 2; }(2)
         << endl;
    auto sum = [](int x, int y)
    { return x + y; }(2, 3);
    cout << sum << endl;

    vector<int> v = {2, -3, 4};
    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 0; })
         << endl;

    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x > 0; })
         << endl;

    cout << none_of(v.begin(), v.end(), [](int x)
                    { return x > 0; })
         << endl;
    return 0;
}