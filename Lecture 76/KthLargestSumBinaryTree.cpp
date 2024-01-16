// 2583
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
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        priority_queue<long long,vector<long long>,greater<long long>> qt;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int i=0;
        long long sum = 0;
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                if(i<k)
                {
                    qt.push(sum);
                    i++;
                }
                else
                {
                    if(qt.top() < sum)
                    {
                        qt.pop();
                        qt.push(sum);
                    }
                }
                sum = 0;
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                sum += temp->val;

                if(temp->left != NULL)
                    q.push(temp->left);

                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }

        if(i<k)
            return -1;

        return qt.top();
    }
};