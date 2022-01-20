// MultiSource BFS
// CodeChef Problem : Snakes and transition from Capitalism to Socialism

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int val[N][N];
int level[N][N];
bool visited[N][N];

void reset()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            level[i][j] = INF;
            visited[i][j] = false;
        }
    }
}

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            mx = max(mx, val[i][j]);
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == mx)
            {
                q.push({i, j});
                visited[i][j] = true;
                level[i][j] = 0;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        int curr_x = curr.first;
        int curr_y = curr.second;
        for (auto movement : movements)
        {
            int child_x = movement.first + curr.first;
            int child_y = movement.second + curr.second;
            if (isValid(child_x, child_y))
            {
                if (!visited[child_x][child_y])
                {
                    q.push({child_x, child_y});
                    visited[child_x][child_y] = true;
                    level[child_x][child_y] = level[curr_x][curr_y] + 1;
                    ans = max(ans, level[child_x][child_y]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> val[i][j];
        }
        cout << bfs() << endl;
    }

    return 0;
}