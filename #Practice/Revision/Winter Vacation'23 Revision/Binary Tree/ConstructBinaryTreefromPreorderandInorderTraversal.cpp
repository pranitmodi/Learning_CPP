// 105
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
    TreeNode* solve(int in_i, int in_j, int pre_i, int pre_j, vector<int>& preorder, vector<int>& inorder)
    {
        int data = preorder[pre_i];
        cout << data << endl;
        TreeNode* temp = new TreeNode(data);

        if(in_i == in_j)
            return temp;

        int ele = in_i;
        while(inorder[ele] != data)
            ele++;

        int d = in_j-ele;
        int ele1 = pre_j-d;

        if(preorder[ele1] == data)
            temp->left = NULL;
        else
            temp->left = solve(in_i,ele-1,pre_i+1,ele1,preorder,inorder);
        
        if(d == 0)
            temp->right = NULL;
        else
            temp->right = solve(ele+1,in_j,ele1+1,pre_j,preorder,inorder);

        return temp;    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        TreeNode *root;
        int n = preorder.size()-1;

        int pre_i = 0;
        int pre_j = n;
        int in_i = 0;
        int in_j = n;

        root = solve(in_i,in_j,pre_i,pre_j,preorder,inorder);
        return root;
    }
};