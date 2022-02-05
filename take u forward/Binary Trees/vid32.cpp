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

int burnTree(node *target, unordered_map<node *, node *> &parent)
{
    int time = 0;
    unordered_map<node *, bool> visited;
    visited[target] = true;
    queue<node *> q;
    q.push(target);

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            auto front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                visited[front->left] = true;
                q.push(front->left);
            }
            if (front->right && !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = true;
                flag = true;
            }
            if (parent[front] && !visited[parent[front]])
            {
                flag = true;
                visited[parent[front]] = true;
                q.push(parent[front]);
            }
        }
        if (flag)
            time++;
    }

    return time;
}

void mark_parents(node *root, unordered_map<node *, node *> &parent)
{
    parent[root] = NULL;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto top = q.front();
            q.pop();

            if (top->left)
                parent[top->left] = top;

            if (top->right)
                parent[top->right] = top;
        }
    }
}

int timeToBurnTree(node *root, node *target)
{

    unordered_map<node *, node *> parent;
    mark_parents(root, parent);

    int maxi = burnTree(target, parent);
    return maxi;
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

    int time = timeToBurnTree(root, root->left);

    cout << time;
    return 0;
}