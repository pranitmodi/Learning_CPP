// 199
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(NULL);
        q.push(root);

        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if(temp != NULL)
            {
                if(temp->right != NULL)
                    q.push(temp->right);

                if(temp->left != NULL)
                    q.push(temp->left);
            }
            else
            {
                if(!q.empty())
                {
                    ans.push_back(q.front()->val);
                    q.push(NULL);
                }
            }
        }

        return ans;
    }
};