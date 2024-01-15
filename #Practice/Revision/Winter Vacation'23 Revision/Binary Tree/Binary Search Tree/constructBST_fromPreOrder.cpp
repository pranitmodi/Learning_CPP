// 1008
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
    TreeNode* insert(int data, TreeNode* root)
    {
        if(root == NULL)
        {
            return new TreeNode(data);
        }

        if(data < root->val)
            root->left = insert(data,root->left);
        else
            root->right = insert(data,root->right);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode *root = NULL;
        for(int i=0; i<preorder.size(); i++)
        {
            root = insert(preorder[i],root);
        }
        return root;
    }
};