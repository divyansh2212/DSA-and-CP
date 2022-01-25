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

bool isTreeSame(node *p, node *q)
{
    if (p == NULL || q == NULL)
        return p == q;

    return (p->data == q->data) && isTreeSame(p->left, q->left) && isTreeSame(p->right, q->right);
}

int main()
{

    return 0;
}