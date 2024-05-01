// 1022. Sum of Root To Leaf Binary Numbers
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
    int binaryToInt(string s)
    {
        int base = 1;
        int ans = 0;

        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == '1')
                ans += base;

            base = base*2;
        }

        return ans;
    }
    void solve(TreeNode *root, int &sum, string str)
    {
        if(root == NULL)
            return;

        if(root->val == 1)
            str += "1";
        else
            str += "0";

        if(root->left == NULL && root->right == NULL)
            sum += binaryToInt(str);

        solve(root->left,sum,str);
        solve(root->right,sum,str);
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        int sum = 0;
        string str = "";

        solve(root,sum,str);
        return sum;
    }
};