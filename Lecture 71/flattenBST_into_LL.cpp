#include <bits/stdc++.h>
using namespace std;
template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

// Approach 1
void InOrder(TreeNode<int>* root, vector<TreeNode<int>*> &v)
{
    if(root == NULL)
        return;

    InOrder(root->left, v);
    v.push_back(root);
    InOrder(root->right, v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int>*> v;
    InOrder(root, v);
    for(int i=0; i<v.size()-1; i++)
    {
        v[i]->left = NULL;
        v[i]->right = v[i+1];
    }
    v[v.size()-1]->left = NULL;
    v[v.size()-1]->right = NULL;
    return v[0];
}

//Approach 2 - Optimal
void InOrder(TreeNode<int>* root, vector<int> &v)
{
    if(root == NULL)
        return;

    InOrder(root->left, v);
    v.push_back(root->data);
    InOrder(root->right, v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> v;
    InOrder(root, v);
    
    TreeNode<int>* newRoot = new TreeNode<int>(v[0]);
    TreeNode<int>* curr = newRoot;

    for(int i=1; i<v.size(); i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(v[i]);
        curr->right = temp;
        curr = temp;
    }

    return newRoot;
}