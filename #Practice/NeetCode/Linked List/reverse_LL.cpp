// leetCode - 206
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
ListNode* reverseList(ListNode* head) 
{
    // better Space Complexity
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;

    ListNode *temp = head->next;
    head->next = NULL;
    if(temp->next == NULL)
    {
        temp->next = head;
        return temp;
    }
    while(temp->next != NULL)
    {
        ListNode *t = temp->next;
        temp->next = head;
        head = temp;
        temp = t;
    }
    temp->next = head;
    return temp;
}

ListNode* reverseList1(ListNode* head) 
{
    // better approach
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* Nxt=NULL;
    while(curr!=NULL)
    {
        Nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Nxt;
    }
    return prev;
}