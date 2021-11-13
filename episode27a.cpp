#include <bits/stdc++.h>
using namespace std;
void print(set<string> &s)
{
    for (auto value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    set<string> s;
    s.insert("abc"); // log(n)
    s.insert("def");
    s.insert("abc");
    s.insert("abcd");
    auto it = s.find("abc"); // log(n)
    if (it != s.end())
    {
        s.erase(it);
    }
    print(s);

    // In unordered_set time complexities are O(1)
    return 0;
}