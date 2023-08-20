// leetCode - 19
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


ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    int c = 0;
    ListNode *temp = head;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    if(c == n)
    {
        return head->next;
    }

    n = c - n;
    c = 0;
    temp = head;

    while(c < n-1)
    {
        temp = temp->next;
        c++;
    }

    ListNode *del = temp->next;
    temp->next = temp->next->next;
    del->next = NULL;
    delete del;
    return head;
}