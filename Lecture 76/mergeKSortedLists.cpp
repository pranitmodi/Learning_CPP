// 23
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class compare
{
    public:
        bool operator() (ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,compare> qt;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
                qt.push(lists[i]);
            }
        }

        while(qt.size() > 0)
        {
            ListNode* temp = qt.top();
            qt.pop();

            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }

            if(temp->next != NULL)
            {
                qt.push(temp->next);
            }
        }

        return head;
    }
};