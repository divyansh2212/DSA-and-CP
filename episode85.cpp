#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+ 10;
int parent[N];
int size[N];

void make(int a)
{
	parent[a] = a;
	size[a] = 1;
}

int find(int a)
{
	if(a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
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
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		make(i);

	while(k--)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	int connected_cts = 0;

	for(int i = 1; i <= n; i++)
	{
		if(find(i) == i)
			connected_cts++;
	}

	cout << connected_cts;
	return 0;
}