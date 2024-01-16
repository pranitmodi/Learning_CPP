#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode 
{        
    public :
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(int data) 
        {
            this -> left = NULL;
            this -> right = NULL;
            this -> data = data;
        }
};
void inOrder(vector<int> &ans, BinaryTreeNode* root)
{
	if(root == NULL)
		return;

    // Inorder of BST is sorted
	inOrder(ans,root->left);
	ans.push_back(root->data);
	inOrder(ans,root->right);
}
BinaryTreeNode* solve(BinaryTreeNode* root, vector<int> &ans, int &i)
{
	if(root == NULL)
		return NULL;
    
    // PreOrder
	root->data = ans[i++];
	root->left = solve(root->left,ans,i);
	root->right = solve(root->right,ans,i);

	return root;
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;
	inOrder(ans,root);

	int i = 0;
	return solve(root,ans,i);
}