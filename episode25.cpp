#include <bits/stdc++.h>
using namespace std;
void print(map<int, string> &M)
{
    cout << M.size() << endl;
    for (auto &val : M)
    {
        cout << val.first << " " << val.second << endl;
    }
    cout << endl;
}
int main()
{
    map<string, string> str;
    str["abcd"] = "abcd"; // O(s.size() * log(n))
    
    map<int, string> m;
    m[1] = "abc"; // O(log(n))
    m[3] = "ghi";
    m[2] = "def";
    m.insert({4, "jkl"});
    m[10];
    print(m);

    auto it1 = m.find(3); // O(log(n))
    if (it1 == m.end())
    {
        cout << "No Value!" << endl;
    }
    else
    {
        cout << it1->first << " " << it1->second << endl;
    }

    auto it2 = m.find(11);
    if (it2 == m.end())
    {
        cout << "No Value!" << endl;
    }
    else
    {
        cout << it2->first << " " << it2->second << endl;
    }
    m.erase(1); // O(log(n))
    m.erase(it1);
    print(m);

    m.clear(); // For clearing map
    print(m);
    return 0;
}