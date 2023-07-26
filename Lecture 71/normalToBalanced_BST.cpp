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



void InOrder(TreeNode<int>* root, vector<int> &v)
{
    if(root == NULL)
        return;

    InOrder(root->left, v);
    v.push_back(root->data);
    InOrder(root->right, v);
}
TreeNode<int>* okay(vector<int> &v, int s, int e)
{
    if(s > e)
        return NULL;

    int mid = s + (e-s)/2;
    TreeNode<int>* newRoot = new TreeNode<int>(v[mid]);
    
    newRoot->left = okay(v,s,mid-1);
    newRoot->right = okay(v,mid+1,e);
    return newRoot;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) 
{
    vector<int> v;
    InOrder(root, v);

    int s = 0;
    int e = v.size()-1;
    return okay(v,s,e);
}