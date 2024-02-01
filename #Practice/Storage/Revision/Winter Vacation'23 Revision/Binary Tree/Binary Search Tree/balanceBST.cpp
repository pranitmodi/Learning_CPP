// 1382
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
    void solve(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;

        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    TreeNode* insert(int s, int e, vector<int> &v)
    {
        if(s>e)
            return NULL;

        int mid = s + (e-s)/2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = insert(s,mid-1,v);
        root->right = insert(mid+1,e,v);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {

        if(root == NULL)
            return NULL;

        vector<int> v;
        solve(root,v);

        return insert(0,v.size()-1,v);
    }
};