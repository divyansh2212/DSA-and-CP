// Pre-Computation with factorial example

/*
Given T testcases and in each testcase a number N.
Print its factorial for each testcase % M, where M = 10^9 + 7.

Constraints:
1 <= T <= 10^5
1 <= N <= 10^5
*/
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
long long fact[N];
int main()
{
    fact[0] = 1, fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }
    return 0;
}