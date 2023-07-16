#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
int height(Node *root)
{
    if(root == NULL)
        return 0;
        
    return(max(height(root->left),height(root->right)) + 1);
}

// Approach 1 (BRUTE FORCE)
bool isBalanced1(Node *root)
{
    if(root == NULL)
        return true;
    
    bool b1 = isBalanced1(root->left);
    bool b2 = isBalanced1(root->right);
    
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
    if(b1 && b2 && diff) // start with the leaf nodes
        return true;
    else
        return false;
}

// Approach 2
pair<int,bool> isBalancedFaster(Node *root)
{
    if(root == NULL)
    {
        pair<int,bool> p = make_pair(0,true);
        return p;
    }

    pair<int,bool> left = isBalancedFaster(root->left);
    pair<int,bool> right = isBalancedFaster(root->right);

    pair<int,bool> ans;
    ans.first = max(left.first,right.first) + 1; //calculating the height

    if(!left.second || !right.second)
        ans.second = false;
    else
        ans.second = abs(left.first - right.first) <= 1; // if till now the nodes have been balanced, then again checking
    return ans;
}
bool isBalanced(Node *root)
{
    return isBalancedFaster(root).second;
}