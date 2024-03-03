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
void solve(vector<int> &ans, int i, Node *root)
{
    if(root == NULL)
        return;
        
    if(ans.size() == i)
        ans.push_back(root->data);
        
    solve(ans,i+1,root->left);
    solve(ans,i+1,root->right);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(ans,0,root);
   return ans;
}