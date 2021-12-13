// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[], vector<int> &visited)
    {
        queue<int> q;
        vector<int> vert;
        vert.push_back(0);
        q.push(0);
        visited[0] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto child : adj[curr])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = 1;
                    vert.push_back(child);
                }
            }
        }
        return vert;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> visited((int)100010, 0);
        vector<int> ans = obj.bfsOfGraph(V, adj, visited);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends