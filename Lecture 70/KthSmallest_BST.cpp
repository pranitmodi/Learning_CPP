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
int kth(BinaryTreeNode* root, int k, int &i)
{
    if(root == NULL)
        return -1;

    int left = kth(root->left,k,i);
    if(left != -1)
        return left;
    
    i++;
    if(i == k)
        return root->data;

    return kth(root->right,k,i);
}
int kthSmallest(BinaryTreeNode* root, int k) 
{
    int i = 0;
    return kth(root,k,i);
}