// 2487. Remove Nodes From Linked List
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        if(head == NULL)
            return head;

        ListNode *curr = head->next;
        ListNode *prev = head;
        prev->next = NULL;
        while(curr->next != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr->next = prev;


        head = curr;
        int maxi = curr->val;
        prev = curr;
        curr = curr->next;
        while(curr!=NULL)
        {
            if(curr->val < maxi)
            {
                prev->next = curr->next;
            }
            else
            {
                maxi = curr->val;
                prev = curr;
            }
            curr = curr->next;
        }

        prev = head;
        curr = head->next;
        if(curr == NULL)
            return prev;
        prev->next = NULL;
        while(curr->next != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr->next = prev;
        return curr;
    }
};