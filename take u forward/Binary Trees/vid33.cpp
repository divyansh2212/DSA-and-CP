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

int heightOfLeft(node *Node)
{
    int h = 0;
    while (Node)
    {
        h++;
        Node = Node->left;
    }
    return h;
}

int heightOfRight(node *Node)
{
    int h = 0;
    while (Node)
    {
        h++;
        Node = Node->right;
    }
    return h;
}

int totalNodesInCompleteBT(node *root)
{
    if (root == NULL)
        return 0;

    int lh = heightOfLeft(root);
    int rh = heightOfRight(root);

    if (lh == rh)
        return (1 << rh) - 1;

    return 1 + totalNodesInCompleteBT(root->left) + totalNodesInCompleteBT(root->right);
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

    cout << totalNodesInCompleteBT(root);
    return 0;
}