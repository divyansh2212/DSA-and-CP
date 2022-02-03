#include <bits/stdc++.h>
using namespace std;

//  Children Sum Property in Binary Tree

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

vector<int> preOrder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        auto top = st.top();
        st.pop();
        ans.push_back(top->data);

        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);
    }
    return ans;
}

void changeBT(node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    
    changeBT(root->left);
    changeBT(root->right);

    int childSum = 0;
    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;
    if (root->left || root->right)
        root->data = childSum;
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

    vector<int> ans = preOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    changeBT(root);

    ans = preOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}