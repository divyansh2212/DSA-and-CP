// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Dijkstra's Algorithm | Shortest Path in Undirected Graphs

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<pair<int, int>> graph[vertices];
    for (int i = 0; i < edges; i++)
    {
        graph[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        graph[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }

    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto front = *st.begin();
        int vtx = front.second;
        st.erase(st.begin());

        for (auto &child : graph[vtx])  
        {
            int childNode = child.first, wt = child.second;
            if (distance[vtx] + wt < distance[childNode])
            {
                distance[childNode] = distance[vtx] + wt;
                st.insert({distance[childNode], childNode});
            }
        }
    }
    return distance;
}
