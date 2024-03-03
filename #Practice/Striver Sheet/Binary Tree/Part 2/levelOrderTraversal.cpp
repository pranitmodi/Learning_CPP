// 102
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> qt;
        qt.push(root);
        qt.push(NULL);

        vector<int> res;

        while(!qt.empty())
        {
            TreeNode *temp = qt.front();
            qt.pop();
            if(temp!=NULL)
            {
                res.push_back(temp->val);
                if(temp->left != NULL)
                    qt.push(temp->left);

                if(temp->right != NULL)
                    qt.push(temp->right);
            }
            else
            {
                ans.push_back(res);
                res.clear();
                if(!qt.empty())
                    qt.push(NULL);
            }
        }    

        return ans;
    }
};