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

class solution
{
    node *prev = NULL;

public:
    void flattenBT(node *root)
    {
        if (root == NULL)
            return;

        flattenBT(root->right);
        flattenBT(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};

void print(node *root)
{
    node *temp = root;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
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

    solution ob;
    ob.flattenBT(root);

    print(root);

    return 0;
}