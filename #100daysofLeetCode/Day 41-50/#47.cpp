// 897. Increasing Order Search Tree
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
    void solve(TreeNode* &curr, TreeNode *root)
    {
        if(root == NULL)
            return;

        solve(curr,root->left);
        curr->right = root;
        curr->left = NULL;
        curr = root;
        solve(curr,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode *head = new TreeNode(-1);
        TreeNode *curr = head;
        solve(curr,root);
        curr->left = NULL;

        return head->right;
    }
};