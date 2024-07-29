// 234
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
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return true;
            
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        while(temp2->next != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp2->next != NULL)
                temp2 = temp2->next;
        }

        ListNode *prev = NULL;
        ListNode *curr = temp1;

        while(curr->next != NULL)
        {
            temp2 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp2;
        }

        curr->next = prev;
        
        temp2 = head;
        while(curr != NULL)
        {
            if(curr->val != temp2->val)
                return false;

            curr = curr->next;
            temp2 = temp2->next;
        }

        return true;
    }
};