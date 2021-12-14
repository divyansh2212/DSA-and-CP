#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool visited[8][8];
int level[8][8];

vector<pair<int, int>> movements = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void reset()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1';
}

int bfs(string src, string dest)
{
    int sourceX = getX(src);
    int sourceY = getY(src);
    int destX = getX(dest);
    int destY = getY(dest);
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});
    visited[sourceX][sourceY] = true;

    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        for(auto movement : movements)
        {
            int movementX = movement.first + curr.first;
            int movementY = movement.second + curr.second;
            if(isValid(movementX, movementY))
            {
                if(!visited[movementX][movementY])
                {
                    visited[movementX][movementY] = true;
                    level[movementX][movementY] = level[curr.first][curr.second] + 1;
                    q.push({movementX, movementY});
                }
            }
        }
    }
    return level[destX][destY];
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
    return 0;
}