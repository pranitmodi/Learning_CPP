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
class Solution {
public:
    void leftPart(Node *root, vector<int> &ans)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
    
        ans.push_back(root->data);
        if(root->left != NULL)
            leftPart(root->left,ans);
        else    
            leftPart(root->right,ans);
    }
    
    void leafNodes(Node *root, vector<int> &ans)
    {
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
    
        if(root->left != NULL)
            leafNodes(root->left,ans);
    
        if(root->right != NULL)
            leafNodes(root->right,ans);
    }
    
    void rightPart(Node *root, vector<int> &ans)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        if(root->right != NULL)
            rightPart(root->right,ans);
        else    
            rightPart(root->left,ans);
    
        // back tracking
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        if(root->left != NULL)
        {
            leftPart(root->left,ans);
            leafNodes(root->left,ans);
        }
    
    
        if(root->right != NULL)
        {
            leafNodes(root->right,ans);
            rightPart(root->right,ans);
        }

    
        return ans;
    }
};