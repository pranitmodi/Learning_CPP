// 142
#include <bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
            
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL)
                fast = fast->next;

            if(slow == fast)
                break;
        }    

        if(fast->next == NULL)
            return NULL;

        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};