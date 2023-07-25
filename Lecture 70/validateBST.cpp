#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode 
{
public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
// One FLAW in this approach
// bool isBST(BinaryTreeNode<int> *root)
// {
//     if(root == NULL || (root->left == NULL && root->right == NULL))
//         return true;
//     bool b1 = false;
//     bool b2 = false;
//     if(root->left != NULL)
//     {
//         if(root->left->data < root->data)
//             b1 = isBST(root->left);
//         else
//             b1 = false;
//     }
//     if(root->right != NULL)
//     {
//         if(root->rigth->data > root->data)
//             b2 = isBST(root->right);
//         else
//             b2 = false;
//     }
//     if(b1 && b2)
//         return true;
//     else
//         return false;
// } 

// Approach 2
bool isBST(BinaryTreeNode *root, int min, int max)
{
    if(root == NULL)
        return true;
    
    if(root->data <= max && root->data >= min)
    {
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);

        return left && right;
    }
    else
        return false;
}
bool validateBST(BinaryTreeNode *root) 
{
    return isBST(root,INT_MIN,INT_MAX);
}