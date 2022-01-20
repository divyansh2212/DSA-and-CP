// 0-1 BFS
// Codechef problem code : REVERSE
// Chef and Reversing

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<int> level(N, INF);
vector<pair<int, int>> g[N];
int n, m;

int bfs()
{
    deque<int> dq;
    dq.push_back(1);
    level[1] = 0;

    while (!dq.empty())
    {
        int curr_vtx = dq.front();
        dq.pop_front();
        for (auto child : g[curr_vtx])
        {
            int child_val = child.first;
            int child_wt = child.second;
            if (level[curr_vtx] + child_wt < level[child_val])
            {
                level[child_val] = level[curr_vtx] + child_wt;
                if (child_wt == 0)
                    dq.push_front(child_val);
                else
                    dq.push_back(child_val);
            }
        }
    }
    return level[n] == INF ? -1 : level[n];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    cout << bfs();
    
    return 0;
}