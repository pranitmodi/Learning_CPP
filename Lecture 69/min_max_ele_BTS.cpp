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
Node* minEle(Node *root)
{
    if(root == NULL)
        return NULL;

    Node *temp = root;
    while(temp->left != NULL)
        temp = temp->left;
    
    return temp;
}
Node* maxEle(Node *root)
{
    if(root == NULL)
        return NULL;

    Node *temp = root;
    while(temp->right != NULL)
        temp = temp->right;
    
    return temp;
}