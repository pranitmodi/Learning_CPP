// leetCode - 141
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
bool hasCycle(ListNode *head)
{
    if(head == NULL || head->next == NULL)
        return false;
        
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != NULL)
    {
        if(fast->next == NULL)
            return false;

        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast)
            return true;
    }
    return false;
}