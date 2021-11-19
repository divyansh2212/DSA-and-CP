#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int main()
{ // To calculate lowest prime and highest prime of every number
    vector<bool> is_prime(N, 1);
    vector<int> hp(N, 0);
    vector<int> lp(N, 0);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i] == true)
        {
            hp[i] = lp[i] = i;
            for (int j = 2 * i; j < N; j = j + i)
            {
                is_prime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }

    // To calculate prime factors of a num
    int num;
    cin >> num;
    vector<int> prime_factors;
    while (num > 1)
    {
        int pf = hp[num];
        while (num % pf == 0)
        {
            prime_factors.push_back(pf);
            num = num / pf;
        }
    }
    for (auto &factrs : prime_factors)
    {
        cout << factrs << " ";
    }
    return 0;
}