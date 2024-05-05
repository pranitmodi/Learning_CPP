// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void solve(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode *&ans)
    {
        if(original == NULL)
            return;

        if(original->val == target->val)
        {
            ans = cloned;
            return;
        }

        solve(original->left,cloned->left,target,ans);
        solve(original->right,cloned->right,target,ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        TreeNode *ans = NULL;
        solve(original,cloned,target,ans);
        return ans;
    }
};