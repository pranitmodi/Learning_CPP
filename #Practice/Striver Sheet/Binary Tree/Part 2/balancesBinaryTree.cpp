// 110
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
    int solve(bool &ans, TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int a = solve(ans,root->left);
        int b = solve(ans,root->right);

        if(abs(a-b) > 1)
            ans = false;

        return (max(a,b) + 1);
    }
    bool isBalanced(TreeNode* root) 
    {
        bool ans = true;
        solve(ans,root);

        return ans;
    }
};