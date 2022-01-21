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

vector<int> postOrder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }

    while (!st2.empty())
    {
        root = st2.top();
        st2.pop();
        ans.push_back(root->data);
    }
    return ans;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> ans = postOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}