#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node * inOrderSuccessor(Node *root, Node *x)
{
    if(root == NULL)
    return NULL;

    // checking in the right subtree
    if(root->data <= x->data)
    {
        while(root->data < x->data)
        {
            root = root->right;
        }
    
        Node *temp = NULL;
        if(root->data == x->data)
        {
            if(root->right == NULL)
                return NULL;
            else
            {
                temp = root->right;
                while(temp->left != NULL)
                temp = temp->left;
                return temp;
            }
        }
    }
    // checking in the left subtree
    if(root->data > x->data)
    {
        Node *a = inOrderSuccessor(root->left,x);
        if(a == NULL)
            return root;
        else
            return a;
    }
}