// Next Greater Element

#include <bits/stdc++.h>
using namespace std;
vector<int> GCD(vector<int> v)
{
    vector<int> gcd(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            gcd[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        gcd[st.top()] = -1;
        st.pop();
    }
    return gcd;
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

    vector<int> gcd = GCD(v);
    for (int i = 0; i < n; i++)
    {
        cout << gcd[i] << " ";
    }

    return 0;
}