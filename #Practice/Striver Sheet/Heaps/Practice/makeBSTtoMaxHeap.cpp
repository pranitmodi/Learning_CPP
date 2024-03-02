#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
class Solution{
  public:
    void inOrder(vector<int> &in, Node* &root)
    {
        if(root == NULL)
            return;
            
        inOrder(in,root->left);
        in.push_back(root->data);
        inOrder(in,root->right);
    }
    void maxHeap(Node* &root,int &i, vector<int> &in)
    {
        if(i<0 || root == NULL)
            return;
            
        root->data = in[i--];
        maxHeap(root->right, i, in);
        maxHeap(root->left, i, in);
    }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> in;
        inOrder(in,root);
        int i = in.size()-1;
        maxHeap(root,i,in);
    }    
};