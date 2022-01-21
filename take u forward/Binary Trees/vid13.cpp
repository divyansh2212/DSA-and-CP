// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverseLL(Node *head)
    {
        Node *prevptr = NULL;
        Node *currptr = head;
        Node *nextptr;
        while (currptr != NULL)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }

    Node *addOne(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                if (temp->data < 9)
                {
                    temp->data++;
                    return head;
                }
            }
            temp = temp->next;
        }

        Node *newhead = reverseLL(head);
        temp = newhead;
        while (temp != NULL)
        {
            if (temp->data != 9)
            {
                temp->data++;
                return head;
            }
        }
        Node *n = new Node(1);
        n->next = head;
        head = n;
        return head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends