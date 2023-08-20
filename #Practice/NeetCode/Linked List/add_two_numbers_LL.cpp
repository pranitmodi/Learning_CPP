// leetCode - 2
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
void insert(ListNode *&head, int data)
{
    ListNode *temp = new ListNode(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }

    ListNode *t = head;
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    ListNode *head;
    int c = 0;
    while(l1 != NULL && l2 != NULL)
    {
        int sum = l1->val + l2->val + c;
        c = 0;
        if(sum > 9)
        {
            c = 1;
            sum = sum % 10;
        }

        insert(head,sum);
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != NULL)
    {
        int sum = l1->val + c;
        c = 0;
        if(sum > 9)
        {
            c = 1;
            sum = sum % 10;
        }
        insert(head,sum);
        l1 = l1->next;
    }

    while(l2 != NULL)
    {
        int sum = l2->val + c;
        c = 0;
        if(sum > 9)
        {
            c = 1;
            sum = sum % 10;
        }
        insert(head,sum);
        l2 = l2->next;
    }

    if(c == 1)
    {
        insert(head,1);
    }

    return head;
}