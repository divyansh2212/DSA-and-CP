// Creation of Tree using Inorder and PreOrder
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

void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

node *buildTreeHelper(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder, int inStart, int inEnd, map<int, int> &mapOfIn)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    node *root = new node(preOrder[preStart]);

    int inRootIdx = mapOfIn[root->data];
    int numsLeft = inRootIdx - inStart;

    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRootIdx - 1, mapOfIn);

    root->right = buildTreeHelper(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRootIdx + 1, inEnd, mapOfIn);

    return root;
}

node *buildTree(vector<int> &preOrder, vector<int> &inOrder)
{
    map<int, int> mapOfIn;
    for (int i = 0; i < inOrder.size(); i++)
        mapOfIn[inOrder[i]] = i;

    node *root = buildTreeHelper(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, mapOfIn);

    return root;
}

int main()
{
    vector<int> preOrder = {1, 2, 4, 5, 3, 6};
    vector<int> inOrder = {4, 2, 5, 1, 6, 3};

    node *root = buildTree(preOrder, inOrder);
    postOrderTraversal(root);
    return 0;
}