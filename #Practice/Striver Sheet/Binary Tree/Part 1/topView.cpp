#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void solve(map<int,int> &m, int i, Node *root)
    {
        if(root == NULL)
            return;
            
        if(m.find(i) == m.end())
            m[i] = root->data;
            
        solve(m,i-1,root->left);
        solve(m,i+1,root->right);
    }
    vector<int> topView(Node *root)
    {
        map<int,int> m;
        vector<int> ans;
        solve(m,0,root);
        
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }

};