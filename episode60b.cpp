#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> divisors[N];
int main()
{
    // To store all divisors of a number
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j = j + i)
        {
            divisors[j].push_back(i);
        }
    }

    for (int i = 2; i <= 10; i++)
    {
        for (auto div : divisors[i])
        {
            cout << div << " ";
        }
        cout << endl;
    }
    return 0;
}