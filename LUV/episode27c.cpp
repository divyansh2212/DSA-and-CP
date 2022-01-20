// Duplicates are allowed in case of multisets
// Time Complexities : O(log(n))
#include <bits/stdc++.h>
using namespace std;
void print(multiset<string> &s)
{
    for (auto value : s)
    {
        cout << value << endl;
    }
}
int main()
{
    multiset<string> s;

    s.insert("abc");
    s.insert("def");
    s.insert("abc");
    print(s);

    auto it = s.find("abc");
    s.erase("abc"); // It will delete all "abc"
    s.erase(it);    // iT will delete only one iterator
    return 0;
}