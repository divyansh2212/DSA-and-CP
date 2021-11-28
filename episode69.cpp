// Adjacency Matrix
// O(N^2) --- Space Complexity
// O(1) --- Searching Time Complexity

// Adjacenecy List
// O(V+E) --- Space Complexity
// O(N) --- Searching Time Complexity
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int graph1[N][N];
vector<pair<int, int>> graph2[];
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;

        graph2[v2].push_back({v1, wt});
        graph2[v1].push_back({v2, wt});
    }

    // i & j are given
    // Adjacency Matrix
    // if(graph[i][j] != 0)
    // {
    //     // connected 
    //     cout << wt; where wt = graph1[i][j];
    // }

    // Adjacency List
    // for(auto child : graph2[i])
    // {
    //     if(child.first == j)
    //     {
    //         // connected
    //         wt = child.second;
    //     }
    // }

    return 0;
}