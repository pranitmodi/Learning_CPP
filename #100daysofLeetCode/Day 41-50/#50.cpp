// 993. Cousins in Binary Tree
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
    void solve(int i, int x, int y,TreeNode *&p, TreeNode *root, int &a, int &b, TreeNode* &aP, TreeNode* &bP)
    {
        if(root == NULL)
            return;

        if(aP == NULL && root->val == x)
        {
            aP = p;
            a = i;
        }

        if(bP == NULL && root->val == y)
        {
            bP = p;
            b = i;
        }

        solve(i+1,x,y,root,root->left,a,b,aP,bP);
        solve(i+1,x,y,root,root->right,a,b,aP,bP);
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(x == y)
            return false;

        int i = 0;
        int a = -1;
        int b = -1;

        TreeNode *aP = NULL;
        TreeNode *bP = NULL;
        TreeNode *p = NULL;

        solve(i,x,y,p,root,a,b,aP,bP);

        if(aP == bP)
            return false;

        if(a == b && a != -1)
            return true;
        else
            return false;
    }
};