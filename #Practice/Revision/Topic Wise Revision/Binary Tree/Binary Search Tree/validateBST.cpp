// 98
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
    bool validate(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(root == NULL)
            return true;

        if((min == NULL || root->val > min->val) && (max == NULL || root->val < max->val))
        {
            bool left = validate(root->left,min,root);
            bool right = validate(root->right,root,max);

            return left && right;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        return validate(root,NULL,NULL);
    }
};