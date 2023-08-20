#include <bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
        int val;
        ListNode* next;

        ListNode(int data)
        {
            this->val = data;
            this->next = NULL;
        }
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    ListNode *temp1;
    ListNode *temp2;
    ListNode *head;
    if(list1->val < list2->val)
    {
        temp1 = list1;
        temp2 = list2;
    }
    else
    {
        temp1 = list2;
        temp2 = list1;
    }
    head = temp1;

    ListNode *nxt = temp1->next;
    while(temp1->next != NULL && temp2->next != NULL)
    {
        if((temp2->val >= temp1->val) && (temp2->val < nxt->val))
        {
            temp1->next = temp2;
            temp2 = temp2->next;
            temp1->next->next = nxt;
            temp1 = temp1->next;
        }
        else
        {
            temp1 = nxt;
            nxt = nxt->next;
        }
    }

    nxt->next = temp2;

    return head;
}