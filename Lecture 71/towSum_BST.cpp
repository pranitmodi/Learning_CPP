#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode 
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
void InOder(vector<int> &v,BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return;

    InOder(v,root->left);
    v.push_back(root->data);
    InOder(v,root->right);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target)
{
	vector<int> v;
    InOder(v,root);
    int i = 0;
    int j = v.size() - 1;
    while(i<j)
    {
        if(v[i] + v[j] == target)
            return true;
        else if(v[i] + v[j] > target)
            j--;
        else
            i++;
    }
    return false;
}