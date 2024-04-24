// 671. Second Minimum Node In a Binary Tree
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
    void solve(int &a, int &b, int &c, TreeNode *root)
    {
        if(root == NULL)
            return;

        if(root->val < a)
        {
            if(root->val < b)
            {
                a = b;
                b = root->val;
            }
            else if(root->val != b)
                a = root->val;
        }
        else if(a == b)
            a = root->val;

        solve(a,b,c,root->left);
        solve(a,b,c,root->right);
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        if(root == NULL)    
            return -1;
        int a = root->val;
        int b = root->val;
        int c = 0;

        solve(a,b,c,root);
        if(a == b)
            return -1;
        else
            return a;
    }
};