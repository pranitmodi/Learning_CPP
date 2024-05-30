// 99. Recover Binary Search Tree
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
    void solve(vector<int> &v, TreeNode *root)
    {
        if(root == NULL)
            return;

        v.push_back(root->val);
        solve(v,root->left);
        solve(v,root->right);
    }
    void okay(vector<int> &v, int &i, TreeNode *root)
    {
        if(root == NULL)
            return;

        okay(v,i,root->left);
        if(i<v.size())
            root->val = v[i++];
        okay(v,i,root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        vector<int> v;
        
        solve(v,root);
        sort(v.begin(),v.end());

        int i=0;
        okay(v,i,root);
    }
};