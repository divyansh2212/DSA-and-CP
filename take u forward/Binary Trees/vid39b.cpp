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

void print(node *root)
{
    node *temp = root;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void flatten(node *root)
{
    if (root == NULL)
        return;

    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        auto curr = st.top();
        st.pop();

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);

        if (!st.empty())
            curr->right = st.top();

        curr->left = NULL;
    }
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


    flatten(root);
    print(root);
    return 0;
}