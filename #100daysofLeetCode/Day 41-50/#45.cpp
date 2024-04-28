// 530. Minimum Absolute Difference in BST
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
    void solve(vector<int> &v, TreeNode* root)
    {
        if(root == NULL)
            return;

        v.push_back(root->val);

        solve(v,root->left);
        solve(v,root->right);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> v;
        solve(v,root);
        sort(v.begin(),v.end());
        int ans = INT_MAX;
        for(int i=0; i<v.size()-1; i++)
        {
            ans = min(ans,(v[i+1]-v[i]));
        }
        return ans;
    }
};