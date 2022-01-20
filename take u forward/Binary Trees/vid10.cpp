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

vector<int> preOrder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *top = st.top();
        st.pop();

        ans.push_back(top->data);
        if (top->right != NULL)
            st.push(top->right);
        if (top->left != NULL)
            st.push(top->left);
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

    vector<int> ans = preOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}