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
int height(struct Node* node)
{
    if(node == NULL)
        return 0;

    return(max(height(node->left),height(node->right)) + 1);
}

// Approach 1
int diameter(Node* root) 
{
    if(root == NULL)
        return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    return (max(op1, max(op2,op3)));
}

// Approach - 2
// Out of pair first is Diameter, second is Height
// Need to -1 in the end
pair<int,int> diameterFast(Node *root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    // recursive calls
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    // the three possible diameters
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1; // out of the heights of left and right

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second,right.second) + 1;
    return ans;
}