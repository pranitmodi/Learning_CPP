#include <bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        while(head->val == val)
        {
            if(head->next == NULL)
                return NULL;
            head = head->next;
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        if(curr == NULL)
            return head;
        while(curr->next != NULL)
        {
            if(curr->val == val)
            {
                curr = curr->next;
                prev->next = curr;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
        if(curr->val == val)
        {
            prev->next = NULL;
        }

        return head;
    }
};