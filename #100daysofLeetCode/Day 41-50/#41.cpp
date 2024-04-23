// 637. Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double sum = 0;
        double count = 0;

        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if(temp!=NULL)
            {
                sum += temp->val;
                count++;
                if(temp->left!=NULL)
                    q.push(temp->left);

                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            else
            {
                ans.push_back(sum/count);
                sum = 0;
                count = 0;
                if(!q.empty())
                    q.push(NULL);
            }
        }

        return ans;
    }
};