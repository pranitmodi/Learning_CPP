// 24. Swap Nodes in Pairs
#include <bits/stdc++.h>
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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *head2 = new ListNode(-1);
        ListNode *ans = head2;
        head2->next = head;
        while(curr!=NULL)
        {
            ListNode *temp = curr->next;
            head2->next = curr;
            curr->next = prev;
            prev->next = temp;
            head2 = prev;
            prev = temp;
            if(prev!=NULL)
                curr = prev->next;
            else
                break;
        }     

        return ans->next;
    }
};