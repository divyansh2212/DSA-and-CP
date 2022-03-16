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

vector<vector<int>> levelOrderZigzag(node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> row(sz);

        for (int i = 0; i < sz; i++)
        {
            int idx = flag == true ? i : (sz - 1 - i);
            node *curr = q.front();
            q.pop();
            row[idx] = curr->data;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        flag = !flag;
        result.push_back(row);
    }
    return result;
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

    vector<vector<int>> ans = levelOrderZigzag(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}