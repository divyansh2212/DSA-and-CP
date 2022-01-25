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

bool isLeaf(node *root)
{
    return root->left == NULL && root->right == NULL;
}

void addLeftBoundary(node *root, vector<int> &ans)
{
    node *curr = root->left;
    while (curr)
    {
        if (isLeaf(curr) == false)
            ans.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeafs(node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    addLeafs(root->left, ans);
    addLeafs(root->right, ans);
}

void addRightBoundary(node *root, vector<int> &ans)
{
    stack<node *> st;
    node *curr = root->right;
    while (curr)
    {
        if (isLeaf(curr) == false)
            st.push(curr);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while (!st.empty())
    {
        node *top = st.top();
        st.pop();
        ans.push_back(top->data);
    }
}

vector<int> printBoundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeafs(root, ans);
    addRightBoundary(root, ans);

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

    vector<int> ans = printBoundary(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}