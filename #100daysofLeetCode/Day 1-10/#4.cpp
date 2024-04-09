// 106 Construct Binary Tree from Inorder and Postorder Traversal
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int in_s,int in_e, int po_s, int po_e)
    {
        int x = postorder[po_e];
        TreeNode* root = new TreeNode(x);
        if (in_s == in_e) 
            return root;

        int i = in_s;
        while (i<in_e && inorder[i] != x)
            i++;

        if(i != in_s)
            root->left = solve(inorder, postorder, in_s, i-1, po_s, po_s +(i-in_s) -1);
        
        if(i < in_e)
            root->right = solve(inorder,postorder,i+1,in_e,po_s+(i-in_s),po_e-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int in_s = 0;
        int in_e = inorder.size() - 1;

        int po_s = 0;
        int po_e = postorder.size() - 1;

        return solve(inorder,postorder,in_s,in_e,po_s,po_e);
    }
};