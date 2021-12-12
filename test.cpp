#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

void bfs(vector<vector<int>> &g,
    	vector<bool> &visited,
    	vector<int> &levels, int s)
{
	queue<int> q;
	q.push(s);
	levels[s] = 0;
	visited[s] = true;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for(auto child : g[curr])
		{
			if(!visited[child])
			{
				levels[child] = levels[curr] + 6;
				visited[child] = true;
				q.push(child);	
			}
		}
	}

}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
    	int n, m, s;
    	cin >> n >> m;
    	vector<vector<int>> g(N);

    	for(int i=0; i < m; i++)
    	{
    		int x, y;
    		cin >> x >> y;
    		g[x].push_back(y);
    		g[y].push_back(x);
    	}
    	cin >> s;

    	vector<bool> visited(n + 1, false);
    	vector<int> levels(n + 1, -1);
    	bfs(g, visited, levels, s);
    	for(int i=1; i <= n; i++)
    	{
    		if(i == s) continue;
    		cout << levels[i] << " ";
    	}
    	cout << endl;
    }
return 0;
}