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

vector<int> inOrder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> st;
    node *ele = root;
    while (1)
    {
        if (ele != NULL)
        {
            st.push(ele);
            ele = ele->left;
        }
        else
        {
            if (st.empty())
                break;
            ele = st.top();
            st.pop();
            ans.push_back(ele->data);
            ele = ele->right;
        }
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

    vector<int> ans = inOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}