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

// Using Recursion
pair<Node*,Node*> solve(Node *root)
{
    if(root == NULL)
    {
        pair<Node*,Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }

    // cout << root->data << endl;

    if(root->left == NULL && root->right == NULL)
    {
        pair<Node*,Node*> p;
        p.first = root;
        p.second = NULL;
        return p;
    }

    pair<Node*,Node*> left,right;

    if(root->left != NULL)
        left = solve(root->left);
    else
    {
        left.first = NULL;
    }

    if(root->right != NULL)
        right = solve(root->right);
    else
    {
        right.first = NULL;
    }
    Node *end;

    if(left.first != NULL && right.first != NULL)
    {
        if(left.second == NULL || right.second == NULL)
        {
            root->right = left.first;
            if(left.second == NULL)
            {
                left.first->right = right.first;
            }
            else
            {
               left.second->right = right.first; 
            }
            end = right.first;
            if(right.second != NULL)
                end = right.second;
        }
        else
        {
            root->right = left.first;
            left.second->right = right.first;
            end = right.second;
        }
    }
    else if(left.first == NULL)
    {
        root->right = right.first;
        if(right.second != NULL)
            end = right.second;
        else
            end = right.first;
    }
    else if(right.first == NULL)
    {
        root->right = left.first;
        if(left.second != NULL)
            end = left.second;
        else
            end = left.first;
    }

    root->left = NULL;

    // cout << root->data << " - " << end->data << endl;

    pair<Node*,Node*> ans;
    ans.first = root;
    ans.second = end;
    return ans;
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(5);
    root->right->right = new Node(6);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
    root->left->right->left = new Node(8);
    root->left->right->left->left = new Node(10);
    root->left->right->left->left->left = new Node(11);
    root->left->right->left->left->left->right = new Node(12);
    root->left->right->left->left->left->left = new Node(13);
    root->left->right->right = new Node(9);

	pair<Node*,Node*> ans = solve(root);
    while(ans.first != ans.second)
    {
        cout << ans.first->data << " ";
        ans.first = ans.first->right;
    }
    cout << ans.first->data << " ";

	return 0;
}