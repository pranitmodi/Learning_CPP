// 2807. Insert Greatest Common Divisors in Linked List
#include<bits/stdc++.h>
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
    int gcd(int a, int b)
    {
        if(b>a)
            return gcd(b,a);

        if(b == 0)
            return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode *prev = head;
        ListNode *curr = head->next;

        while(curr!=NULL)
        {
            int w = gcd(curr->val,prev->val);
            ListNode *temp = new ListNode(w);
            prev->next = temp;
            temp->next = curr;
            curr = curr->next;
            prev = temp->next;
        }

        return head;
    }
};