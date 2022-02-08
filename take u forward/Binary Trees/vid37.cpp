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

void preOrderPrint(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

string serialize(node *root)
{
    if (root == NULL)
        return "";

    string s = "";
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *currNode = q.front();
        q.pop();

        if (currNode == NULL)
            s.append("#,");
        else
            s.append(to_string(currNode->data) + ',');

        if (currNode != NULL)
        {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;
}

node *deserialize(string treeData)
{
    if (treeData.size() == 0)
        return NULL;

    stringstream s(treeData);
    string str;
    getline(s, str, ',');

    node *root = new node(stoi(str));
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *currNode = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            currNode->left = NULL;
        else
        {
            currNode->left = new node(stoi(str));
            q.push(currNode->left);
        }

        getline(s, str, ',');
        if (str == "#")
            currNode->right = NULL;
        else
        {
            currNode->right = new node(stoi(str));
            q.push(currNode->right);
        }
    }
    return root;
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

    cout << serialize(root) << endl;

    preOrderPrint(deserialize(serialize(root)));

    return 0;
}