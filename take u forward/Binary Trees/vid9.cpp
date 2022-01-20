// BFS in Binary Tree
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

vector<int> bfs(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
            ans.push_back(front->data);
        }
    }
    return ans;
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
    
    vector<int> ans = bfs(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}