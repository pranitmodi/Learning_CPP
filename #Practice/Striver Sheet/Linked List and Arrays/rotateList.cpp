// 61
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int lengthList(ListNode* head)
    {
        int c = 0;
        ListNode *temp = head;

        while(temp!=NULL)
        {
            temp = temp->next;
            c++;
        }

        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || k == 0)
            return head;

        int l = lengthList(head);
        if(k == l)
            return head;

        k = k%l;

        if(k == 0)
            return head;

        int r = l - k;
        ListNode *temp = head;

        while(r>1)
        {
            temp = temp->next;
            r--;
        }

        ListNode *temp1 = temp->next;
        temp->next = NULL;
        temp = head;
        head = temp1;

        while(temp1->next != NULL)
            temp1 = temp1->next;

        temp1->next = temp;
        return head;
    }
};