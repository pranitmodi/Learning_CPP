// 111
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
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(!left) // if the node does not have a left subtree
            return 1 + right;
        else if(!right) // if the node does not have a right subtree
            return 1 + left;
        else
            return (1 + min(left,right));
    }
};