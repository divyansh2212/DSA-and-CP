#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;

int bfs(int n, vector<int> &level, vector<bool> &visited, vector<vector<int>> &g)
{
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto child : g[curr])
        {
            if(!visited[child])
            {
                q.push(child);
                level[child] = level[curr] + 1;
                visited[child] = 1;
            }
        }
    }
    return level[n];
}

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        vector<vector<int>> g(N);
        vector<int> level(N, 0);
        vector<bool> visited(N, false);
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << bfs(n, level, visited, g) << endl;
    }


    return 0;
}
