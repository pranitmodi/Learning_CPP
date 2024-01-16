#include <bits/stdc++.h>
using namespace std;
// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
  public:
    int nodes(struct Node* tree)
    {
        if(tree == NULL)
            return 0;
            
        return(1 + nodes(tree->left) + nodes(tree->right));
    }
    bool isComplete(struct Node* tree, int i, int cn)
    {
        if(tree == NULL)
            return true;
            
        if(i >= cn)
        {
            return false;
        }
        
        return(isComplete(tree->left,2*i + 1,cn) && isComplete(tree->right,2*i + 2,cn));
    }
    bool isMaxOrder(struct Node* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        
        if(root->right == NULL)
        {
            if(root->data > root->left->data)
                return true;
        }
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return(left && right 
                && (root->data > root->left->data) 
                && (root->data > root->right->data));
        }
    }
    bool isHeap(struct Node* tree) 
    {
        int cn = nodes(tree);
        return(isComplete(tree,0,cn) && isMaxOrder(tree));
    }
};