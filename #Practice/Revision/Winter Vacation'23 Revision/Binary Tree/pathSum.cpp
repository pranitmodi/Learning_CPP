// 112
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
    void sumMax(TreeNode* root,int s, int targetSum, bool &ans)
    {
        if(root == NULL)
            return;

        s = s + root->val;

        if(root->left == NULL && root->right == NULL)
        {
            if(s == targetSum)
                ans = true;

            return;
        }

        sumMax(root->left,s,targetSum,ans);
        sumMax(root->right,s,targetSum,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int s = 0;
        bool ans = false;
        sumMax(root,s,targetSum,ans);
        return ans;
    }
};