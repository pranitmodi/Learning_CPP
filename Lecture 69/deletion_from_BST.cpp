#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            left = right = NULL;
        }

        ~Node()
        {
            cout << "Node deleted of value " << data << endl;
        }
};
Node* deletefromBST(Node *root, int val)
{
    if(root == NULL)
        return root;
    
    if(root->data == val)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        else if(root->left == NULL)
        {
            Node *temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }
            root->data = temp->data;
            root->left = deletefromBST(root->left,temp->data);
        }
    }
    else if(root->data < val)
    {
        root->right = deletefromBST(root->right,val);
        return root;
    }
    else
    {
        root->left = deletefromBST(root->left,val);
        return root;
    }
}
Node *deleteNode(Node *root, int X) 
{
    root = deletefromBST(root,X);
    return root;
}