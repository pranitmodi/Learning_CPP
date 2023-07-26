#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() 
        {
            if (left)
            {
                delete left;
            }

            if (right)
            {
                elete right;
            }
        }   
};

// Approach 1
void InOrder(TreeNode<int> *root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    InOrder(root->left,v);
    v.push_back(root->data);
    InOrder(root->right,v);
}
TreeNode<int>* tree(vector<int> &v3, int s, int e)
{
    if(s>e)
        return NULL;

    int mid = s + (e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(v3[mid]);
    root->left = tree(v3,s,mid-1);
    root->right = tree(v3,mid+1,e);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    vector<int> v1;
    InOrder(root1,v1);
    vector<int> v2;
    InOrder(root2,v2);

    vector<int> v3(v1.size() + v2.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] <= v2[j])
            v3[k++] = v1[i++];
        else
            v3[k++] = v2[j++];
    }

    while(i < v1.size())
        v3[k++] = v1[i++];

    while(j < v2.size())
        v3[k++] = v2[j++];

    return tree(v3,0,v3.size()-1);
}

// Approach 2