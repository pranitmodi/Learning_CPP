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
        }
};
Node* buildTree(Node *root)
{
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter data for the left of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter data for the right of " << data << ": ";
    root->right = buildTree(root->right);
}
void levelOrderTraversal(Node *root)
{
    queue<Node*> qt;
    qt.push(root);
    qt.push(NULL);

    cout << "Level Order: " << endl;

    while(!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        if(temp != NULL)
        {
            cout << temp->data << " ";
            if(temp->left != NULL)
                qt.push(temp->left);

            if(temp->right != NULL)    
                qt.push(temp->right);
        }
        else
        {
            cout << endl;
            if(!qt.empty())
                qt.push(NULL);
        }
    }
}
void reverseLevelOrderTraversal(Node *root)
{
    queue<Node*> qt;
    stack<Node*> s;
    qt.push(root);
    qt.push(NULL);

    while(!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        if(temp != NULL)
        {
            s.push(temp);

            if(temp->right != NULL)    
                qt.push(temp->right);

            if(temp->left != NULL)
                qt.push(temp->left);
        }
        else
        {
            cout << endl;
            if(!qt.empty())
            {
                qt.push(NULL);
                s.push(NULL);
            }
        }
    }

    cout << "Reverse Order: " << endl;
    while(!s.empty())
    {
        if(s.top() == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << s.top()->data << " "; 
        }
        s.pop();
    }
}
int main()
{
    cout << "Enter the data for the root node: " << endl;
    Node *root;
    root = buildTree(root);
    levelOrderTraversal(root);
    reverseLevelOrderTraversal(root);
}