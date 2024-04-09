// 147 - Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *front = new ListNode(-6000);
        ListNode *temp = head;

        while(temp != NULL)
        {
            ListNode *temp2 = front;
            while(temp2->next != NULL && temp2->next->val<temp->val)
            {
                temp2 = temp2->next;
            }
            ListNode* t = temp->next;
            ListNode* t2 = temp2->next;
            temp2->next = temp;
            temp->next = t2;

            temp = t;
        }

        return front->next;
    }
};