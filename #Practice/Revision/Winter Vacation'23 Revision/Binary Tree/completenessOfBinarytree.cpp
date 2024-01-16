// 958
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
    void nodes(TreeNode *root,int &w)
    {
        if(root == NULL)
            return;

        w++;
        nodes(root->left,w);
        nodes(root->right,w);
    }
    bool solve(TreeNode *root, int i, int w)
    {
        if(root == NULL)
            return true;

        if(i >= w)
        {
            return false;
        }

        bool left = solve(root->left,2*i + 1,w);
        bool right = solve(root->right,2*i + 2,w);

        return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int w = 0;
        nodes(root,w);

        return solve(root,0,w);
    }
};