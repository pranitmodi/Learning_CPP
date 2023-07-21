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

Node* solve(int *in, int *&pr, int n, int i)
{
    if(i == 1)
    {
        Node *only = new Node(in[0]);
        return only;
    }

    int ele = pr[0];
    Node *next = new Node(ele);

    int j;
    for(j=0; j<i; j++)
    {
        if(in[j] == ele)
            break;
    }

    if(j == 0)
        next->left = NULL;
    else
    {
        pr = pr + 1;
        next->left = solve(in,pr,n,j);
    }

    if(j == i-1)
        next->right = NULL;
    else
    {
        pr = pr + 1;
        next->right = solve(in+j+1,pr,n,i-j-1);
    }

    return next;
}
Node* buildTree(int in[], int pre[], int n)
{
    Node *root = solve(in,pre,n,n);
    return root;
}