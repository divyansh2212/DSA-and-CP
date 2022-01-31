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

bool isSymmetricHelp(node *left, node *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    return left->data == right->data;

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(node *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);

    cout << isSymmetric(root);
    return 0;
}