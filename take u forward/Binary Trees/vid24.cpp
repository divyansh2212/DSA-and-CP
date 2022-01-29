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

vector<int> bottomView(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        node *ele = it.first;
        int line = it.second;
        m[line] = ele->data;

        if (ele->left)
            q.push({ele->left, line - 1});

        if (ele->right)
            q.push({ele->right, line + 1});
    }

    for (auto p : m)
        ans.push_back(p.second);

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

    vector<int> ans = bottomView(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}