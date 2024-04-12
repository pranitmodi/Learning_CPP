// 1367. Linked List in Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
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
    bool check(ListNode* head, TreeNode* root)
    {
        if(head == NULL)
            return true;
            
        if(head->next != NULL)
        {
            if(root == NULL)
                return false;
                
            bool a = false;
            bool b = false;

            if(root->left != NULL && root->left->val == head->next->val)
                a = check(head->next,root->left);
            if(root->right != NULL && root->right->val == head->next->val)
                b = check(head->next,root->right);

            return (a || b);
        }
        else
            return true;
        
    }
    void solve(bool &ans, ListNode* head, TreeNode* root)
    {
        if(root == NULL)
            return;

        if(root->val == head->val && !ans)
            ans = check(head,root);

        solve(ans,head,root->left);
        solve(ans,head,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool ans = false;
        solve(ans,head,root);
        return ans;
    }
};