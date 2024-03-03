// 987
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
    void solve(TreeNode* root, map<int,map<int,vector<int>>> &m, int r,int c)
    {
        if(root == NULL)
            return;

        m[c][r].push_back(root->val);
        solve(root->left,m,r-1,c-1);
        solve(root->right,m,r-1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,map<int,vector<int>>> m;
        solve(root,m,0,0);
        vector<vector<int>> ans;

        for(auto i:m)
        {
            vector<int> res;
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    res.push_back(k);
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};