// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Kruskal's Algorithm

int find_par(int a, vector<int> &parent)
{
    if (a == parent[a])
        return a;
    return parent[a] = find_par(parent[a], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &ranks)
{
    u = find_par(u, parent);
    v = find_par(v, parent);

    if (ranks[u] < ranks[v])
        parent[u] = v;
    else if (ranks[v] < ranks[u])
        parent[v] = u;
    else
    {
        parent[u] = v;
        ranks[v]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n), ranks(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<pair<int, int>> mst;
    int cost = 0;

    for (auto &it : edges)
    {
        int wt = it.first, v = it.second.first, u = it.second.second;
        if (find_par(u, parent) != find_par(v, parent))
        {
            cost += wt;
            Union(u, v, parent, ranks);
            mst.push_back({u, v});
        }
    }

    cout << cost << endl;
    for (auto &it : mst)
        cout << it.first << " - " << it.second << endl;
        
    return 0;
}