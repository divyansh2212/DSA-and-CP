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

void mark_parents(node *root, unordered_map<node *, node *> &parent)
{
    parent[root] = NULL;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->left)
        {
            q.push(front->left);
            parent[front->left] = front;
        }
        if (front->right)
        {
            q.push(front->right);
            parent[front->right] = front;
        }
    }
}

vector<int> nodesAtDistK(node *root, node *target, int k)
{
    unordered_map<node *, node *> parent;
    mark_parents(root, parent);

    unordered_map<node *, bool> visited;
    visited[target] = true;
    int curr_level = 0;
    queue<node *> q;
    q.push(target);

    while (!q.empty())
    {
        if (curr_level == k)
            break;
        curr_level++;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                visited[front->left] = true;
                q.push(front->left);
            }
            if (front->right && !visited[front->right])
            {
                visited[front->right] = true;
                q.push(front->right);
            }
            if (parent[front] && !visited[parent[front]])
            {
                visited[parent[front]] = true;
                q.push(parent[front]);
            }
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        node *top = q.front();
        q.pop();
        result.push_back(top->data);
    }
    return result;
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

    vector<int> ans = nodesAtDistK(root, root->left, 1);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}