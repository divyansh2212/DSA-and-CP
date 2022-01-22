#include <bits/stdc++.h>
using namespace std;

class node
{
public:
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

vector<int> inOrder(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<node *> st;

    while (1)
    {
        if (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if (st.empty())
                break;
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
        }
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

    vector<int> ans = preOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;

    vector<int> ans2 = inOrder(root);

    for (int i = 0; i < ans2.size(); i++)
        cout << ans2[i] << " ";

    cout << endl;

    vector<int> ans3 = postOrder(root);

    for (int i = 0; i < ans3.size(); i++)
        cout << ans3[i] << " ";

    cout << endl;

    return 0;
}