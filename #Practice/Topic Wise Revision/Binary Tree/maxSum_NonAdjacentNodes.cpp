#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution{
  public:
    pair<int,int> solve(Node *root)
    {
        if(root == NULL)
        {
            pair<int,int> ans = make_pair(0,0);
            return ans;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> ans;
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first,left.second) + max(right.first,right.second);
        
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};