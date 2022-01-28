#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val, left = NULL, right = NULL;
    }
};

vector<vector<int>> verticalTraversal(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<pair<node *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        node *ele = front.first;
        int x = front.second.first, y = front.second.second;
        nodes[x][y].insert(ele->data);

        if (ele->left)
            q.push({ele->left, {x - 1, y + 1}});
        if (ele->right)
            q.push({ele->right, {x + 1, y + 1}});
    }

    for (auto p : nodes)
    {
        vector<int> col;
        
        for (auto q : p.second)
            col.insert(col.end(), q.second.begin(), q.second.end());

        ans.push_back(col);
    }
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> ans = verticalTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}