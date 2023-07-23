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

void solve(Node *root)
{
    if(root == NULL)
        return;

    Node *curr = root;
    Node *prev;

    while(curr != NULL)
    {
        if(curr->left != NULL)
        {
            prev = curr->left;

            while(prev->right != NULL)
                prev = prev->right;
            
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
void flatten(Node *root)
{
    solve(root);
}

