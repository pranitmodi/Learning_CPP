// leetCode - 226
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
class Solution 
{
    public:
        TreeNode* invert(TreeNode* root)
        {
            if(root == NULL)
                return NULL;

            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;

            root->left = invert(root->left);
            root->right = invert(root->right);

            return root;
        }
        TreeNode* invertTree(TreeNode* root) 
        {
            return invert(root);
        }
};