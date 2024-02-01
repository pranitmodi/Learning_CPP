// 86
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
ListNode* partition(ListNode* head, int x) 
{
    if(head == NULL)
        return head;

    ListNode* temp1 = NULL;
    ListNode* temp2 = NULL;

    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    ListNode* temp = head;

    while(temp->next != NULL)
    {
        // cout << temp->val << endl;
        if(temp->val < x)
        {
            if(head1 == NULL)
            {
                head1 = temp;
                temp1 = temp;
            }
            else
            {
                temp1->next = temp;
                temp1 = temp1->next;
            }
        }
        else
        {
            if(head2 == NULL)
            {
                head2 = temp;
                temp2 = temp;
            }
            else
            {
                temp2->next = temp;
                temp2 = temp2->next;
            }
        }

        temp = temp->next;
    }

    if(temp->val < x)
    {
        if(head1 == NULL)
        {
            head1 = temp;
            temp1 = temp;
        }
        else
        {
            temp1->next = temp;
            temp1 = temp1->next;
        }
    }
    else
    {
        if(head2 == NULL)
        {
            head2 = temp;
            temp2 = temp;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
    }

    if(head1 != NULL && head2 != NULL)
    {
        cout << temp1->val << endl;
        cout << head2->val << endl;
        temp1->next = head2;
        temp2->next = NULL;
        head = head1;
    }
    return head;
}