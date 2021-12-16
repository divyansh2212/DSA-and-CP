#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e9 + 7;
int val[N][N];
//bool visited[N][N];
int n, m, q;
long long ans = 0;

void reset()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            val[i][j] = 0;
       //     visited[i][j] = false;
        }
    }
}

vector<pair<int, int>> movements = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                    {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m && val[i][j] == 1;
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    while(!q.empty())
    {
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        auto curr = q.front();
        visited[curr.first][curr.second] = true;
        
        q.pop();
        for(auto movement : movements)
        {
            int child_x = movement.first + curr.first;
            int child_y = movement.second + curr.second;
            if(isValid(child_x, child_y) && !visited[child_x][child_y])
            {
                visited[child_x][child_y] = true;
                q.push({child_x, child_y});
                ans += 2;
            }
        }
    }
}

int main()
{   
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> q;
        reset();
        ans = 0;
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            val[x-1][y-1] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(val[i][j] == 1)
                {
                    bfs(i, j);
                }
            }
        }
        cout << (ans % M) << endl;
    }
    return 0;
}