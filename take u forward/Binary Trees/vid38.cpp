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

    node *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else if (curr->left)
        {
            node *prev = curr->left;

            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else if (prev->right == curr)
            {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
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

    vector<int> inord = inOrder(root);
    for (int i = 0; i < inord.size(); i++)
        cout << inord[i] << " ";
    cout << endl;
    return 0;
}