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

int widthOfBinaryTree(node *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int mnm = q.front().second;

        int last, first;
        for (int i = 0; i < size; i++)
        {
            node *nod = q.front().first;
            int curr_idx = q.front().second - mnm;
            q.pop();

            if (i == 0)
                first = curr_idx;
            if (i == size - 1)
                last = curr_idx;

            if (nod->left)
                q.push({nod->left, 2 * curr_idx + 1});
            if (nod->right)
                q.push({nod->right, 2 * curr_idx + 2});
        }
        ans = max(ans, last - first + 1);
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

    int width = widthOfBinaryTree(root);
    cout << width;
    return 0;
}