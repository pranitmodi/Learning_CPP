#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode 
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left){
            delete left;
        }
        if (right){
            delete right;
        }
    }
};


BinaryTreeNode<int>* solve(vector<int> &preorder, int &i, int min, int max)
{
    if(i == preorder.size())
        return NULL;

    if(preorder[i] < min || preorder[i] > max)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);

    // same values we are passing which we are checking next time
    //if(preorder[i] > min && preorder[i] < root->data)
        root->left = solve(preorder,i,min,root->data); 
    //if(preorder[i] < max && preorder[i] > root->data)
        root->right = solve(preorder,i,root->data,max);

    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) 
{
    int i = 0;
    BinaryTreeNode<int>* root = solve(preorder,i,INT_MIN,INT_MAX);
    return root;
}