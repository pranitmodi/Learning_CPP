#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() 
        {
            if (left)
            {
                delete left;
            }

            if (right)
            {
                delete right;
            }
        }   
};

//Approach 1
void InOrder(TreeNode<int> *root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    InOrder(root->left,v);
    v.push_back(root->data);
    InOrder(root->right,v);
}
TreeNode<int>* tree(vector<int> &v3, int s, int e)
{
    if(s>e)
        return NULL;

    int mid = s + (e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(v3[mid]);
    root->left = tree(v3,s,mid-1);
    root->right = tree(v3,mid+1,e);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    vector<int> v1;
    InOrder(root1,v1);
    vector<int> v2;
    InOrder(root2,v2);

    vector<int> v3(v1.size() + v2.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] <= v2[j])
            v3[k++] = v1[i++];
        else
            v3[k++] = v2[j++];
    }

    while(i < v1.size())
        v3[k++] = v1[i++];

    while(j < v2.size())
        v3[k++] = v2[j++];

    return tree(v3,0,v3.size()-1);
}

// Approach 2
void BSTtoDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if(root == NULL)
        return;

    BSTtoDLL(root->right,head);
    root->right = head;

    if(head != NULL)
        head->left = root;
    
    head = root;

    BSTtoDLL(root->left,head);
}
TreeNode<int>* mergeLL(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(root1 != NULL && root2 != NULL) 
    {
        if(root1->data < root2->data)
        {
            if(head == NULL)
            {
                head = root1;
                tail = root1;
            }
            else
            {
                tail->right = root1;
                root1->left = tail;
                tail = root1;
            }
            root1 = root1->right;
        }
        else
        {
            if(head == NULL)
            {
                head = root2;
                tail = root2;
            }
            else
            {
                tail->right = root2;
                root2->left = tail;
                tail = root2;
            }
            root2 = root2->right;
        }
    }

    while(root1 != NULL)
    {
        tail->right = root1;
        root1->left = tail;
        tail = root1;
        root1 = root1->right;
    }

    while(root2 != NULL)
    {
        tail->right = root2;
        root2->left = tail;
        tail = root2;
        root2 = root2->right;
    }

    return head;
}
int count(TreeNode<int> *head)
{
    int c = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL)
    {
        c++;
        temp = temp->right;
    }
    return c;
}
TreeNode<int> *sortedMergedBST(TreeNode<int> *&head, int n)
{
    if(n<=0 || head == NULL)
        return NULL;
    
    TreeNode<int> *left = sortedMergedBST(head,n/2);

    TreeNode<int> *root = head;
    root->left = left;

    head = head->right;
    root->right = sortedMergedBST(head,n-n/2-1);

    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int> *temp1 = NULL;
    BSTtoDLL(root1,temp1);
    temp1->left = NULL;
    TreeNode<int> *temp2 = NULL;
    BSTtoDLL(root2,temp2);
    temp2->left = NULL;

    TreeNode<int> *head;
    head = mergeLL(temp1,temp2);
    int n = count(head);

    return sortedMergedBST(head,n);
}