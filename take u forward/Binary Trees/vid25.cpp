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

void leftView(node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}

void rightView(node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (ans.size() == level)
        ans.push_back(root->data);

    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
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

    vector<int> leftviewvec;
    leftView(root, 0, leftviewvec);

    for (int i = 0; i < leftviewvec.size(); i++)
        cout << leftviewvec[i] << " ";

    cout << endl;

    vector<int> rightviewvec;
    rightView(root, 0, rightviewvec);

    for (int i = 0; i < rightviewvec.size(); i++)
        cout << rightviewvec[i] << " ";

    return 0;
}