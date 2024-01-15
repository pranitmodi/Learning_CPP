#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class info
{
    public:
        int maxi; // data at node should be greater than the maximum node in the left subtree 
        int mini; // data at node should be smaller than minimum node in the right subtree
        bool isBST;
        int size;
};
class Solution{
    public:
    info solve(Node* root, int &ans)
    {
        if(root == NULL)
            return {INT_MIN,INT_MAX,true,0};
            
        info temp1 = solve(root->left,ans);
        info temp2 = solve(root->right,ans);
        
        info temp;
        
        temp.size = temp1.size + temp2.size + 1;
        temp.maxi = max(root->data,temp2.maxi);
        temp.mini = min(root->data,temp1.mini);
        
        if(root->data < temp2.mini && root->data > temp1.maxi && (temp1.isBST && temp2.isBST))
        {
            temp.isBST = true;
        }
        else
            temp.isBST = false;
    
        if(temp.isBST)
        {
            ans = max(ans,temp.size);
        }
        
        // cout << root->data << " : " << temp.isBST << endl;
    
        return temp;
    }
    int largestBst(Node *root)
    {
    	int ans = 0;
        info temp = solve(root,ans);
        return ans;
    }
};