#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
bool visited[N];
vector<int> dist(N, INF);

void dijikstra(int source)
{
    set<pair<int, int>> st;
    dist[source] = 0;

    st.insert({0, source});

    while (st.size() > 0)
    {
        auto curr = *st.begin();
        st.erase(st.begin());
        int curr_dist = curr.first;
        int curr_node = curr.second;
        if (visited[curr_node])
            continue;
        visited[curr_node] = 1;

        for (auto child : g[curr_node])
        {
            int wt = child.second;
            int child_node = child.first;
            if (curr_dist + wt < dist[child_node])
            {
                dist[child_node] = curr_dist + wt;
                st.insert({dist[child_node], child_node});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    return 0;
}