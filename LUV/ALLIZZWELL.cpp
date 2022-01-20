#include <bits/stdc++.h>
using namespace std;
const string s = "ALLIZZWELL";
// const string s2 = "LLEWZZILLA";

bool dfs(int i, int j, vector<vector<char>> &vec, int idx, vector<vector<bool>> &visited)
{
    bool isWordExists = false;

    int r = vec.size(), c = vec[0].size();
    if (i >= r || i < 0 || j >= c || j < 0 || (visited[i][j] == true))
        return false;
    if (vec[i][j] != s[idx])
        return false;

    visited[i][j] = true;
    if (idx == s.length() - 1 && vec[i][j] == s[idx])
        return true;
    vector<vector<bool>> c_visited = visited;
    
    isWordExists |= dfs(i + 1, j, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i - 1, j, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i, j + 1, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i, j - 1, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i + 1, j + 1, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i + 1, j - 1, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i - 1, j - 1, vec, idx + 1, visited);
    visited = c_visited;
    isWordExists |= dfs(i - 1, j + 1, vec, idx + 1, visited);

    return isWordExists;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<char>> vec(r, vector<char>(c, '0'));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cin >> vec[i][j];
        }

        bool isWordExists = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                vector<vector<bool>> visited(r, vector<bool>(c, false));
                isWordExists |= dfs(i, j, vec, 0, visited);
                if (isWordExists)
                    break;
            }
            if (isWordExists)
                break;
        }

        if (isWordExists)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}