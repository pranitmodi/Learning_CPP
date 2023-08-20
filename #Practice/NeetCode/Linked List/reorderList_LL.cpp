// leetCode - 143
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

// find the middle node
// from there split the LL into two
// reverse the second LL
// Keep adding onr eleemnt from the second LL to the first
class Solution 
{
    public:
    ListNode* middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next != NULL)
        {
            if(fast->next->next != NULL)
                fast = fast->next->next;
            else
                break;

            slow = slow->next;
        }

        return slow;
    }
    ListNode* reverseList(ListNode* head) 
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
    void reorderList(ListNode* head) 
    {
        ListNode *mid = middle(head);
        ListNode *head2 = reverseList(mid->next);
        mid->next = NULL;

        while(head != NULL && head2 != NULL) 
        {
            ListNode *temp1 = head->next;
            ListNode *temp2 = head2->next;

            head->next = head2;
            head2->next = temp1;
            head = temp1;
            head2 = temp2;
        }
    }
};