// Inorder Traversal with O(1) space complexity
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
vector<int> morisTraversal(TreeNode* root) 
{
    vector<int> ans;
    TreeNode* curr = root;

    while(curr != NULL)
    {
        // check for curr->left and pre->right
        if(curr->left == NULL)
        {
            ans.push_back(curr->val); //store
            curr = curr->right; // right
        }
        else
        {
            TreeNode* pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;

            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left; // left
            }
            else
            {
                pre->right = NULL;
                ans.push_back(curr->val); //store
                curr = curr->right; //right
            }
        }
    }

    return ans;
}