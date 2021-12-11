// SPOJ NAKANJ
// Shortest path using level traversal

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool visited[8][8];
int level[8][8];

vector<pair<int, int>> movements =
    {{2, -1}, {2, 1}, {-2, -1}, {-2, 1}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2}};

int getX(string s) { return s[0] - 'a'; }
int getY(string s) { return s[1] - '1'; };

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            visited[i][j] = 0;
            level[i][j] = 0;
        }
    }
}
bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int bfs(string source, string dest)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    visited[sourceX][sourceY] = true;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();

        for (auto movement : movements)
        {
            int childX = movement.first + x;
            int childY = movement.second + y;
            if (!isValid(childX, childY))
                continue;

            if (!visited[childX][childY])
            {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                visited[childX][childY] = true;
            }
        }
    }
    return level[destX][destY];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }

    return 0;
}