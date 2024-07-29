// 404
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
    bool check(TreeNode *root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    void solve(TreeNode *root, int &s)
    {
        if(root == NULL)
            return;

        if(root->left != NULL && check(root->left))
        {
            s = s+root->left->val;
        }

        solve(root->left,s);
        solve(root->right,s);
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int s = 0;
        solve(root,s);
        return s;
    }
};