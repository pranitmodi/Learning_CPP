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
void inOrder(Node *root)
{
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    Node *root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "Enter data at node: ";
    root = buildTree(root);

    cout << "InOrder: ";
    inOrder(root);

    return 0;
}