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

vector<vector<int>> levelOrderZigZag(node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            int idx = flag ? i : (size - i - 1);
            row[idx] = front->data;

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
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

    vector<vector<int>> ans = levelOrderZigZag(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }

    return 0;
}