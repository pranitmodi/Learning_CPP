#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
class Solution
{
public:
    void solve(Node*root,pair<int,int> p,pair<int,int> &ans)
    {
        if(root == NULL)
            return;
            
        int s = p.first + root->data;
        int level = p.second;
        if(root->left == NULL && root->right == NULL)
        {
            if(level > ans.second)
            {
                ans.first = s;
                ans.second = level;
            }
            else if(level == ans.second)
            {
                if(s > ans.first)
                    ans.first = s;
            }
            
            return;
        }
        
        pair<int,int> w = make_pair(s,level+1);
        
        solve(root->left,w,ans);
        solve(root->right,w,ans);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int,int> ans;
        pair<int,int> p = make_pair(0,0);
        
        solve(root,p,ans);
        return ans.first;
    }
};