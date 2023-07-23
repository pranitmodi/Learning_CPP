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

void Morris(Node *root)
{
    if(root == NULL)
        return;

    Node *curr = root;
    Node *pre = NULL;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while((pre->right != NULL) && (pre->right != curr))
                pre = pre->right;

            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
int main()
{

	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
*/
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
    root->right->right = new Node(6);
	root->left->left = new Node(4);
    root->left->left->right = new Node(7);
	root->left->right = new Node(5);

	Morris(root);

	return 0;
}