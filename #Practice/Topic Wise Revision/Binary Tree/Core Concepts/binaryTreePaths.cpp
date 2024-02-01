// 257
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
    void solve(vector<string> &ans,string s, TreeNode* root)
    {
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL)
        {
            s = s + to_string(root->val);
            ans.push_back(s);
        }
        else
        {
            s = s + to_string(root->val) + "->";
            solve(ans,s,root->left);
            solve(ans,s,root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        solve(ans,s,root);
        return ans;
    }
};