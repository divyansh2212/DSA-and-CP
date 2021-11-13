// Balanced Paranthesis
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> m = {{'{', -1}, {'}', 1}, {'(', -2}, {')', 2}, {'[', -3}, {']', 3}};
string isBalanced(string s)
{
    stack<char> st;
    for (auto brackets : s)
    {
        if (m[brackets] < 0)
        {
            st.push(brackets);
        }
        else
        {
            if (st.empty())
                return "NO";

            char Top = st.top();
            st.pop();

            if (m[Top] + m[brackets] != 0)
                return "NO";
        }
    }
    if (!st.empty())
        return "NO";
    return "YES";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }

    return 0;
}