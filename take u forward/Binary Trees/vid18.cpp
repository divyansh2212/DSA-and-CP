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

int dfsHeight(node *root, int &maxPthSum)
{
    if (root == NULL)
        return 0;

    int lsum = max(0, dfsHeight(root->left, maxPthSum));
    int rsum = max(0, dfsHeight(root->right, maxPthSum));

    maxPthSum = max(maxPthSum, root->data + lsum + rsum);

    return root->data + max(lsum, rsum);
}

int maxPath(node *root)
{
    int maxSum = 0;
    dfsHeight(root, maxSum);
    return maxSum;
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

    cout << maxPath(root);
    return 0;
}