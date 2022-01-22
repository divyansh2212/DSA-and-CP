#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;

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

void traversals(node *root)
{
    if(root == NULL)
    return;
    stack<pair<node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else if (it.second == 3)
        {
            post.push_back(it.first->data);
        }
    }
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
    traversals(root);

    for (int i = 0; i < pre.size(); i++)
        cout << pre[i] << " ";

    cout << endl;

    for (int i = 0; i < in.size(); i++)
        cout << in[i] << " ";

    cout << endl;

    for (int i = 0; i < post.size(); i++)
        cout << post[i] << " ";

    return 0;
}