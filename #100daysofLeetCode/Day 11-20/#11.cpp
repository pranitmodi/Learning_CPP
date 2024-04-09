// 25 Reverse Nodes in k-Group
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
    pair<ListNode*,ListNode*> solve(ListNode* root, int k)
    {
        ListNode *prev = root;
        ListNode *curr = root->next;

        int i = 1; 
        while(i<k)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            i++;
        }
        return make_pair(prev,curr);
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *curr = head;
        int c = 0;
        while(curr!=NULL)
        {
            c++;
            curr = curr->next;
        }    
        if(c<2 || k == 1)
            return head;

        ListNode* tail = head;
        ListNode* ans = head;
        curr = head;
        int i = 0;
        while(i+k<=c)
        {
            pair<ListNode*,ListNode*> p = solve(curr,k);
            ListNode* t12 = curr;
            if(curr == head)
            {
                ans = p.first;
                tail = curr;
            }
            else
            {
                tail->next = p.first;
                tail = curr;
            }

            if(p.second == NULL)
            {
                tail->next = NULL;
                curr = NULL;
                break;
            }
            curr = p.second;
            i += k;
        }
        if(curr!=NULL)
            tail->next = curr;

        return ans;
    }
};