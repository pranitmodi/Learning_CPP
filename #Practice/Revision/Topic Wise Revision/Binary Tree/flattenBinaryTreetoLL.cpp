// 114
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
    TreeNode* solve(TreeNode *root)
    {
        if(root == NULL)
            return NULL;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        left = solve(left);
        right = solve(right);

        if(left != NULL)
        {
            root->right = left;
            TreeNode *temp = left;
            while(temp->right != NULL)
                temp = temp->right;

            temp->right = right;
        }
        else
        {
            root->right = right;
        }
        
        return root;
    }
    void flatten(TreeNode* root) 
    {
        root = solve(root);
    }
};