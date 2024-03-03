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
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q, bool &a,bool &b, TreeNode *&ans)
    {
        if(root == NULL)
            return false;

        // beacuse we need to know if the element was in the node's subtree or not
        bool b1 = solve(root->left,p,q,a,b,ans);
        bool b2 = solve(root->right,p,q,a,b,ans);

        if(b1 && b2)
        {
            if(ans==NULL)
                ans = root;
            return true;
        }
        else if(root == p || root == q)
        {
            if(b1 || b2)
                ans = root;
            return true;
        }
        else 
            return (b1 || b2);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *ans = NULL;
        bool a = false;
        bool b = false;
        bool c = solve(root,p,q,a,b,ans);
        return ans;    
    }
};