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

bool helper(node *root, vector<int> &ans, int val)
{
    if (root == NULL)
        return false;

    ans.push_back(root->data);

    if (root->data == val)
        return true;

    if (helper(root->left, ans, val) || helper(root->right, ans, val))
        return true;

    ans.pop_back();
    return false;
}

vector<int> getPath(node *root, int val)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    helper(root, ans, val);

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

    vector<int> ans = getPath(root, 7);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}