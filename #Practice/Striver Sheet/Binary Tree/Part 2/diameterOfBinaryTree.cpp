// 543
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
    int maxDepth(int &ans, TreeNode* root) 
    {
        if(root == NULL)
            return 0;

        int a = maxDepth(ans,root->left);
        int b = maxDepth(ans,root->right);

        ans = max(ans,a+b);

        return max(a,b) + 1;    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int height = maxDepth(ans,root);
        return ans;
    }
};