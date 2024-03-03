// 94
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        TreeNode *curr = root;

        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr)
                    pred = pred->right;

                if(pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }            
                else
                {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};