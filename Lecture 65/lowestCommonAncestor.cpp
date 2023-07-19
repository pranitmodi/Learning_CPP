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
int findNode(Node* root, Node* &ans ,int n1 ,int n2)
{
    if(root == NULL)
        return 0;
        
    if(root->data == n1 || root->data == n2) 
    {
        ans = root; // if they both are in same branch, then the moment we find the first element thats the answer
        return 1;
    }
    
    int b1 = findNode(root->left,ans,n1,n2);
    int b2 = findNode(root->right,ans,n1,n2);
    
    if(b1==1 && b2==1)//  for when both are in different branches and thus now only two will be returned, thus no changing of ans
    {
        ans = root;
        return 2;
    }
    else if(b1 == 2 || b2 == 2)
    {
        return 2;   // if either one part is 2 we have find our answer node 
    }
    else if((b1 == 1) || (b2 == 1)) // if either one of them is 1, we have find onr part
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
Node* lca(Node* root ,int n1 ,int n2 )
{
    Node *ans;
    int i = findNode(root,ans,n1,n2);
    return ans;
}