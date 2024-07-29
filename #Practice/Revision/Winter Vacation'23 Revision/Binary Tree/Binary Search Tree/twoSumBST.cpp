// 653
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
    // //Approach 1
    // void solve(TreeNode* root, int k, map<int,bool> &m, bool &ans)
    // {
    //     if(root == NULL)
    //         return;

    //     solve(root->left,k,m,ans);

    //     if(m[k-(root->val)])
    //         ans = true;
    //     else
    //         m[root->val] = true;

    //     solve(root->right,k,m,ans);
    // }
    // bool findTarget(TreeNode* root, int k) 
    // {
    //     bool ans = false;
    //     map<int,bool> m;
    //     solve(root,k,m,ans);
    //     return ans;
    // }

    // Approach 2
    void solve(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;

        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> v;
        solve(root,v);

        int i=0;
        int j=v.size()-1;
        int sum;

        while(i<j)
        {
            sum = v[i] + v[j];
            if(sum == k)
                return true;
            if(sum > k)
                j--;
            else
                i++;
        }

        return false;
    }
};