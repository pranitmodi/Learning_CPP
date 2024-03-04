// 160
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
    int length(ListNode *n)
    {
        int c = 0;
        while(n!=NULL)
        {
            n = n->next;
            c++;
        }

        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = length(headA);
        int c2 = length(headB);

        if(c2>c1)
            return getIntersectionNode(headB,headA);

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;

        while(c1>c2)
        {
            temp1 = temp1->next;
            c1--;
        }

        while(temp1 != NULL)
        {
            if(temp1 == temp2)
                return temp1;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};