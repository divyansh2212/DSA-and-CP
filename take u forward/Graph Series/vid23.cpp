// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
#define ll long long

int parent[N];
int ranks[N];

void make_set()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find_par(int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = find_par(parent[node]);
}

void Union(int u, int v)
{
    u = find_par(u);
    v = find_par(v);

    if (ranks[u] < ranks[v])
        parent[u] = v;
    else if (ranks[v] < ranks[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        ranks[u]++;
    }
}

int main()
{
    make_set();
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    if (find_par(2) != find_par(3))
        cout << "Different Components\n";
    else
        cout << "Same Components\n";

    return 0;
}