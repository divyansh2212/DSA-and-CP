#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n, m;
int val[N][N];
int ans = 0, fnl_ans = 0;

vector<pair<int, int>> movements = {{1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};

bool isValid(int i, int j, int prev)
{
    return i >= 0 && j >= 0 && i < n && j < m && val[i][j] == prev + 1;
}

void dfs(int i, int j, vector<vector<bool>>& visited)
{
    visited[i][j] = true;
    ans++;
    int prev = val[i][j];

    for(auto movement : movements)
    {
        int child_x = i + movement.first;
        int child_y = j + movement.second;
        if(isValid(child_x, child_y, prev))
        {
            if(visited[child_x][child_y]) continue;
            dfs(child_x, child_y, visited);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;
            val[i][j] = c;
        }
    }
    int x, y;
    cin >> x >> y;
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    int k = 0; int cased;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            ++k;
            if(val[i][j] == 65)
            {   
                ans = 0;
                dfs(i, j, visited);
                if(fnl_ans < ans)
                {
                    fnl_ans = max(fnl_ans, ans);
                    cased = k;
                }
            }
        }
    }

 //   cout << "Case 1:" << fnl_ans;
    cout << "Case " << cased << ":" << fnl_ans;
    return 0;
}