#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int M = 1e9 + 7;
long long fact[N];

int binExp(long long a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b = (b >> 1);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
            continue;
        ans.push_back('.');
        int x = s[i] - 'A';
        if(x >= 0 && x <= 26)
            ans.push_back('a' + x);
        else
            ans.push_back(s[i]);
    }
    cout << ans;
    return 0;
}