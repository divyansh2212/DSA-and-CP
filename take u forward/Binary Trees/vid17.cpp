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

int dfsHeight(node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = dfsHeight(root->left, diameter);

    int rh = dfsHeight(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBT(node *root)
{
    int diameter = 0;

    dfsHeight(root, diameter);

    return diameter;
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

    cout << diameterOfBT(root);
    return 0;
}