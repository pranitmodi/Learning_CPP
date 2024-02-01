// 450
#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return NULL;

        if(root->val == key)
        {
            if(root->left == NULL && root->right == NULL)
                return NULL;
            else if(root->left == NULL)
            {
                TreeNode *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right == NULL)
            {
                TreeNode *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                TreeNode* temp = root->left;
                while(temp->right != NULL)
                    temp = temp->right;

                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
            }
        }   
        else if(root->val < key)
        {
            root->right = deleteNode(root->right,key);
        } 
        else
        {
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};