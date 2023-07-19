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

Node* solve(Node *root, int &k, int node)
{
    if(root == NULL)
        return NULL;
    
    if(root->data == node)
        return root;

    Node *left = solve(root->left,k,node);
    Node *right = solve(root->right,k,node);

    if(left != NULL && right == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if(right != NULL && left == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans =  solve(root,k,node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}