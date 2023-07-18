#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
void rightView1(Node *root, int level, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);

    if(root->right != NULL)
        rightView1(root->right,level+1,ans);

    if(root->left != NULL)
        rightView1(root->left,level+1,ans);
}
vector<int> rightView(Node *root)
{
    vector <int> ans;
    rightView1(root,0,ans);
    return ans;
}