// 129
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
    void solve(string s,int &sum, TreeNode* root)
    {
        if(root == NULL)
            return;

        s = s + to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            sum = sum + stoi(s);
        }
        else
        {
            solve(s,sum,root->left);
            solve(s,sum,root->right);
        }
    }
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        string s = "";
        solve(s,sum,root);
        return sum;
    }
};