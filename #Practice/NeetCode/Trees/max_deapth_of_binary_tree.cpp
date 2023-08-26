// leetCode - 104
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
        int height(TreeNode* root)
        {
            if(root == NULL)
                return 0;

            int a = height(root->left);
            int b = height(root->right);

            return (max(a,b) + 1);
        }
        int maxDepth(TreeNode* root) 
        {
            return height(root);
        }
};