// 938
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
    void solve(TreeNode* root, int low, int high, int &ans)
    {
        if(root == NULL)
            return;

        if(root->val > low)
            solve(root->left,low,high,ans);

        if(root->val >= low && root->val <=high)
            ans += root->val;

        if(root->val < high)
            solve(root->right,low,high,ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        solve(root,low,high,ans);
        return ans;
    }
};