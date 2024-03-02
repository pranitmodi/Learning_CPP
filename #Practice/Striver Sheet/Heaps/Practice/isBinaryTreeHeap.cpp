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

class Solution {
  public:

    bool isCBT(int cnt, struct Node *tree, int i)
    {
        if(tree == NULL)
            return true;
            
        if(tree->left != NULL)
        {
            if((2*i)>cnt)
                return false;
        }
        
        if(tree->right != NULL)
        {
            if((2*i)+1 > cnt)
                return false;
        }
        
        return (isCBT(cnt,tree->left,(2*i)) && isCBT(cnt,tree->right,(2*i)+1));
    }

    bool isMaxOrder(struct Node *tree)
    {
        if(tree == NULL)
            return true;
            
        if(tree->left != NULL && tree->data<=tree->left->data)
            return false;
        
        if(tree->right != NULL && tree->data<=tree->right->data)
            return false;
            
        return(isMaxOrder(tree->left) && isMaxOrder(tree->right));
    }

    void count(int &cnt, struct Node *tree)
    {
        if(tree == NULL)
            return;
            
        cnt++;
        count(cnt,tree->left);
        count(cnt,tree->right);
    }
    
    bool isHeap(struct Node* tree) 
    {
        int cnt = 0;
        count(cnt,tree);
        
        if(isCBT(cnt, tree, 1) && isMaxOrder(tree))
            return true;
        return false;
    }
};