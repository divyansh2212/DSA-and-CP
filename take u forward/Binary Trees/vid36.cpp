// Creation of Tree using Inorder and PostOrder
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

node *buidlTreeHelper(vector<int> &inOrder, int inStart, int inEnd, vector<int> &postOrder, int postStart, int postEnd, map<int, int> &mapOfIn)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    node *root = new node(postOrder[postEnd]);
    int inRootIdx = mapOfIn[root->data];
    int numsLeft = inRootIdx - inStart;

    root->left = buidlTreeHelper(inOrder, inStart, inRootIdx - 1, postOrder, postStart, postStart + numsLeft - 1, mapOfIn);

    root->right = buidlTreeHelper(inOrder, inRootIdx + 1, inEnd, postOrder, postStart + numsLeft, postEnd - 1, mapOfIn);

    return root;
}

node *buildTree(vector<int> &inOrder, vector<int> &postOrder)
{
    if (inOrder.size() != postOrder.size())
        return NULL;

    map<int, int> mapOfIn;
    for (int i = 0; i < inOrder.size(); i++)
        mapOfIn[inOrder[i]] = i;

    node *root = buidlTreeHelper(inOrder, 0, inOrder.size() - 1, postOrder, 0, postOrder.size() - 1, mapOfIn);

    return root;
}

void preOrderPrint(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main()
{
    vector<int> inOrder = {40, 20, 50, 10, 60, 30};
    vector<int> postOrder = {40, 50, 20, 60, 30, 10};

    node *root = buildTree(inOrder, postOrder);

    preOrderPrint(root);

    return 0;
}