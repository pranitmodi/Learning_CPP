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
};
bool searchInBST(Node *root, int x)
{
    if(root == NULL)
        return false;
    
    if(root->data == x)
        return true;
    else if(x > root->data)
        return search(root->right,x);
    else
        return search(root->left,x);
}