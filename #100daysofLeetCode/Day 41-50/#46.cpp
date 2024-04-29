// 563. Binary Tree Tilt
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
    int solve(int &ans, TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int a = solve(ans,root->left);
        int b = solve(ans,root->right);

        int sum = a + b + root->val;
        root->val = abs(a-b);
        ans += abs(a-b);
        return sum; 
    }
    int findTilt(TreeNode* root) 
    {
        int ans = 0;
        int a = solve(ans,root);
        return ans;
    }
};