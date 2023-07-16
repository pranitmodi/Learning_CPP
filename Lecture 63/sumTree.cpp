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
pair<int,bool> sumTree(Node *root)
{
    if(root == NULL) // if only one sub part of the node is NULL
    {
        pair<int,bool> p = make_pair(0,true);
        return p;
    }
    if(root->left == NULL && root->right == NULL) // if both NULL, then leaf node
    {
        pair<int,bool> p = make_pair(root->data,true);
        return p;
    }

    pair<int,bool> left = sumTree(root->left);
    pair<int,bool> right = sumTree(root->right);

    pair<int,bool> ans;

    // if condition is true and both subtrees are individually true, because for all nodes
    if((root->data == (left.first + right.first)) && left.second && right.second)
        ans.second = true;
    else
        ans.second = false;

    ans.first = root->data + left.first + right.first;
    return ans;
}
bool isSumTree(Node* root)
{
    return sumTree(root).second;
}