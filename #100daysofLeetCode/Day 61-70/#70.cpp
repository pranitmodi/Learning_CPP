// 109. Convert Sorted List to Binary Search Tree
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    ListNode* middle(ListNode *root)
    {
        ListNode* temp1 = root;
        ListNode* temp2 = root;
        ListNode* temp = root;

        while(temp2!=NULL && temp2->next != NULL)
        {
            temp2 = temp2->next;
            temp2 = temp2->next;
            temp = temp1;
            temp1 = temp1->next;
        }

        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return new TreeNode(head->val);

        ListNode* temp = middle(head);
        if(temp!=NULL && temp->next != NULL)
        {
            ListNode* mid = temp->next;
            TreeNode* t = new TreeNode(mid->val);
            temp->next = NULL;
            t->left = sortedListToBST(head);
            t->right = sortedListToBST(mid->next);
            return t;
        }
        else 
            return NULL;
    }
};