// 103
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> v;
        stack<int> s;
        int c = 0;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                c = !c;
        
                while(!s.empty())
                {
                    v.push_back(s.top());
                    s.pop();
                }
                if(v.size() > 0)
                {
                    ans.push_back(v); 
                    v.clear();
                }

                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                if(c == 0)
                {
                    v.push_back(temp->val);
                }
                else
                {
                    s.push(temp->val);
                }

                if(temp->left != NULL)
                    q.push(temp->left);
                
                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }

        return ans;
    }
};