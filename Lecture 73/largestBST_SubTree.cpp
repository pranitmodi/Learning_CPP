#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode 
{
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() 
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

class info
{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};
info solve(TreeNode<int>* root, int &maxSize)
{
    if(root == NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }

    info temp1 = solve(root->left,maxSize);
    info temp2 = solve(root->right,maxSize);

    info temp;

    temp.size = temp1.size + temp2.size + 1;
    temp.maxi = max(temp2.maxi,root->data);
    temp.mini = min(temp1.mini,root->data);

    if(root->data < temp2.mini && root->data > temp1.maxi && (temp1.isBST && temp2.isBST))
    {
        temp.isBST = true;
    }
    else
        temp.isBST = false;

    if(temp.isBST)
    {
        maxSize = max(maxSize,temp.size);
    }

    return temp;
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;
}
