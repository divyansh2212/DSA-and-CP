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

int heightOfLeft(node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}

int heightOfRight(node *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}

int totalNodesInCompleteBT(node *root)
{
    if (root == NULL)
        return 0;

    int lh = heightOfLeft(root->left);
    int rh = heightOfRight(root->right);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + totalNodesInCompleteBT(root->left) + totalNodesInCompleteBT(root->right);
}

int main()
{

    return 0;
}