#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode 
{
public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
pair<int,int> predecessorSuccessor(BinaryTreeNode* root, int key)
{
    BinaryTreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }


    BinaryTreeNode *predd = temp->left;
    while(predd != NULL)
    {
        pred = predd->data;
        predd = predd->right;
    }

    BinaryTreeNode *succc = temp->right;
    while(succc != NULL)
    {
        succ = succc->data;
        succc = succc->left;
    }

    pair<int,int> p = make_pair(pred,succ);
    return p;
}