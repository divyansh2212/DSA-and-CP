// Breadth First Search
// Time Complexity: O(V + E)

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int levels[N];
bool visited[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int curr_vtx = q.front();
        q.pop();
        for (auto child : g[curr_vtx])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                levels[child] = levels[curr_vtx] + 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "node: " << i << ", level: " << levels[i] << endl;
    }
    return 0;
}