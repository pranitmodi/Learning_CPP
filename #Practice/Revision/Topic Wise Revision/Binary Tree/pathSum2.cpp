// 113
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
    void solve(TreeNode* root, int ele, vector<vector<int>> &ans, vector<int> v, int s)
    {
        if(root == NULL)
            return;

        s = s + root->val;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(s == ele)
            {
                ans.push_back(v);
                v.clear();
            }
        }
        else
        {
            solve(root->left,ele,ans,v,s);
            solve(root->right,ele,ans,v,s);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        int s = 0;
        solve(root,targetSum,ans,v,s);
        return ans;
    }
};