// 236
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
    int solve(TreeNode* root, TreeNode* p, TreeNode* q, bool &a, bool &b, TreeNode *&ans)
    {
        if(root == NULL)
            return 0;

        if(a && b)
            return 0;

        // TO SEE IF AN ELEMENT WAS FOUND IN THE SUB-TREE OR NOT
        int t = solve(root->left,p,q,a,b,ans);
        int v = solve(root->right,p,q,a,b,ans);

        if(t && v && ans == NULL)
        {
            ans = root;
            return 1;
        }

        int r = 0;
        if(root->val == p->val)
        {
            if((t || v) && ans == NULL)
                ans = root;
            a = true;
            r = 1;
        }

        if(root->val == q->val)
        {
            if((t || v) && ans == NULL)
                ans = root;
            b = true;
            r = 1;
        }

        return (r || t || v);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // TO KEEP A TRACK OF IF ELEMENTS ARE FOUND
        bool a = false;
        bool b = false;
        TreeNode* ans = NULL;

        solve(root,p,q,a,b,ans);
        return ans;
    }
};