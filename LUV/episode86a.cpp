// Code Monk --> City and Flood

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];

void make(int v)
{
	parent[v] = v;
	size[v] = 1;
}

int find(int v)
{
	if(parent[v] == v)
		return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a != b)
	{
		if(size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

int main()
{
	int n, k;
	cin >> n;
	for(int i = 1; i <= n; i++)
		make(i);

	cin >> k;
	while(k--)
	{
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if(find(i) == i)
			cnt++;
	cout << cnt;

	return 0;
}