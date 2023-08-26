// leetCode - 543
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
    pair<int,int> diameter(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);

        int a = left.first;
        int b = right.first;
        int c = left.second + right.second + 1;

        pair<int,int> p;
        p.first = max(a,max(b,c));
        p.second = max(left.second,right.second) + 1;
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return diameter(root).first-1;
    }
};