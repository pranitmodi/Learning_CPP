#include <bits/stdc++.h>
using namespace std;
class Node
{
    public: 
        int data;
        Node *left;
        Node *right;

        Node(int data)        
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL; 
            // cout << "Created for " << data << endl;
        }
};
Node* buildTree(Node *root)
{
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter the data for left of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for right of " << data << ": " << endl;
    root->right = buildTree(root->right);
}

// Level Order Traversal
void levelOrderTraversal(Node *root)
{
    // We use Queue
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // for seperators

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// Reverse Order Traversal
void reverseOrderTraversal(Node *root)
{
    // We use Queue
    queue<Node*>q;
    stack<Node*>s;
    q.push(root);
    q.push(NULL); // for seperators
    s.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
                s.push(NULL);
            }
        }
        else
        {
            s.push(temp);

            if(temp->right != NULL)
                q.push(temp->right);

            if(temp->left != NULL)
                q.push(temp->left);
        }
    }

    while(!s.empty())
    {
        if(s.top() == NULL)
            cout << endl;
        else
        {
            cout << s.top()->data << " ";
        }
        s.pop();
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter Data for the root node: ";
    root = buildTree(root);

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "Reverse Order Traversal: " << endl;
    reverseOrderTraversal(root);

    return 0;
}