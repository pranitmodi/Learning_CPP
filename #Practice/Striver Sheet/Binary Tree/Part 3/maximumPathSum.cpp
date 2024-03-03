// 124
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
    int solve(int &ans, TreeNode *root)
    {
        if(root == NULL)
            return 0;

        int a = solve(ans,root->left);
        int b = solve(ans,root->right);

        int d1 = max(root->val,a+b+root->val);
        int d2 = max(a+root->val,b+root->val);
        int d = max(d1,d2);
        ans = max(ans,d);
        
        // we pass only the maximum of(root+maximum out of the children) or the root itself
        return max(d2,root->val);
    }
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        int w = solve(ans,root);
        return ans;    
    }
};