#include <bits/stdc++.h>
using namespace std;
template <typename T>
    class BinaryTreeNode 
    {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

// Traversing in can be done in any order, but prefer InOrder
void countLeafNodes(BinaryTreeNode<int> *root, int &count)
{
    if(root == NULL) // this is necessary for parent node with single child
        return;
    
    countLeafNodes(root->left,count);
    // And when the Node comes after L in LNR, we check the node
    // if true, after updating count, we can return from there itself
    if(root->left == NULL && root->right == NULL)
    {
        count++;
        return;
    }
    countLeafNodes(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    countLeafNodes(root,count);
    return count;
}