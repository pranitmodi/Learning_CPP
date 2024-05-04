// 501. Find Mode in Binary Search Tree
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
    void solve(TreeNode *root, map<int,int> &m)
    {
        if(root == NULL)
            return;

        m[root->val]++;

        solve(root->left,m);
        solve(root->right,m);
    }
    vector<int> findMode(TreeNode* root) 
    {
        map<int,int> m;
        solve(root,m);
        vector<int> ans;

        int c = 0;
        for(auto i:m)
        {
            if(i.second > c)
            {
                c = i.second;
                ans.clear();
                ans.push_back(i.first);
            }
            else if(i.second == c)
                ans.push_back(i.first);
        }

        return ans;
    }
};