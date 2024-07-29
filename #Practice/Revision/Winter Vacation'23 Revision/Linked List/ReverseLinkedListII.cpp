// 92
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;

        if(left == 1)
        {
            int c = 1;
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *temp = NULL;
            while(c<right)
            {
                c++;
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            temp = curr->next;
            curr->next = prev;
            head->next = temp;
            return curr;
        }


        int c = 2;
        ListNode *temp = head;
        
        while(c<left && temp->next!=NULL)
        {
            c++;
            temp = temp->next;
        }

        if(c!=left || temp->next == NULL)
            return head;

        ListNode *l1 = temp->next;
        ListNode *l2 = l1;
        c++;

        while(c<right && l2->next!= NULL)
        {
            c++;
            l2 = l2->next;
        }

        if(c<right)
            return head;

        ListNode *r1 = l2->next;
        ListNode *r2 = r1->next;

        ListNode *prev = l1;
        ListNode *curr = prev->next;

        while(curr != r2)
        {
            ListNode *temp2 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp2;
        }

        
        if(left == 1)
        {
            l1->next = curr;
            return prev;
        }

        temp->next = prev;
        l1->next = curr;

        return head;
    }
};