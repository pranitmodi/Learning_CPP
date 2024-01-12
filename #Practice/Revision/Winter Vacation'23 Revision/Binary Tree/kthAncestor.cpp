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
int solve(Node *root, int &ans, int &w, int node)
{
    if(root == NULL)
        return 0;
        
    int v = solve(root->left,ans,w,node);
    int t = solve(root->right,ans,w,node);
    
    if(v || t)
    {
        w--;
        if(w == 0 && ans == -1)
            ans = root->data;
        return 1;
    }
    
    if(root->data == node)
    {
        return 1;
    }
    
    return 0;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    int w = k;
    solve(root,ans,w,node);
    return(ans);
}