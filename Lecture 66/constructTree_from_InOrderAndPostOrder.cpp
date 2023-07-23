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
Node* solve(int *in, int *post, int k)
{
    if(k == 1)
    {
        Node *ans = new Node(post[0]);
        return ans;
    }
    
    int ele = post[k-1];
    Node *ans = new Node(ele);
    
    int j=0;
    while(in[j] != ele)
        j++;
    
    if(j == 0)
        ans->left = NULL;
    else
        ans->left = solve(in,post,j);

    if(j == k-1)
        ans->right = NULL;
    else
        ans->right = solve(in+j+1,post+j,k-j-1);

    return ans;
}
Node *buildTree(int in[], int post[], int n) 
{
    Node *root = solve(in,post,n);
    return root;
}