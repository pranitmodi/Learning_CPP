// 1019
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
    void reverse(ListNode *&head)
    {
        if(head == NULL || head->next == NULL)
            return;

        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr->next != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        curr->next = prev;
        head = curr;
    }
    int length(ListNode *head)
    {
        if(head == NULL)
            return 0;

        int l = 0;
        ListNode *temp = head;

        while(temp != NULL)
        {
            l++;
            temp = temp->next;
        }

        return l;
    }
    vector<int> nextLargerNodes(ListNode* head) 
    {
        reverse(head);
        int l = length(head);
        vector<int> ans(l);

        l--;
        stack<int> st;
        st.push(0);

        ListNode *temp = head;
        while(temp != NULL)
        {
            int d = temp->val;
            while(st.top()!=0 && st.top()<=d)
                st.pop();

            ans[l--] = st.top();
            st.push(d);

            temp = temp->next;
        }

        reverse(head);
        return ans;
    }
};