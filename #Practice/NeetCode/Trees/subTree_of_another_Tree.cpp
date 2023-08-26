// leetCode - 572
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        else if(p != NULL && q != NULL)
        {
            if(p->val == q->val)
            {
                return(isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
            }
            return false;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL)
            return false;
        
        bool b;
        if(root->val == subRoot->val)
        {
            b = isSameTree(root,subRoot);
        }
        
        return(b || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};