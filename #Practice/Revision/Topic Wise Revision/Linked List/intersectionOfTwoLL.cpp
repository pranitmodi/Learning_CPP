// 160
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
class Solution {
public:
    int lengthList(ListNode *head)
    {
        ListNode *temp = head;
        int c = 0;

        while(temp != NULL)
        {
            c++;
            temp = temp->next;
        }

        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * ans = NULL;
        int c1 = lengthList(headA);
        int c2 = lengthList(headB);

        ListNode *temp1;
        ListNode *temp2;

        if(c1 <= c2)
        {
            temp1 = headB;
            temp2 = headA;
        }
        else
        {
            temp1 = headA;
            temp2 = headB;
        }

        int maxi = max(c1,c2);
        int mini = min(c1,c2);

        while(maxi > mini)
        {
            maxi--;
            temp1 = temp1->next;
        }

        while(maxi>0)
        {
            if(temp1 == temp2)
                return temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;
            maxi--;
        }

        return NULL;
    }
};