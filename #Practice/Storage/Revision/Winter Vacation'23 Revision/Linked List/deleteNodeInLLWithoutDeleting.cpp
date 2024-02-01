// 237
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
    void deleteNode(ListNode* node) {
        ListNode* n = node->next;

        while(n->next != NULL)
        {
            node->val = n->val;
            node = n;
            n = n->next;
        }
        node->val = n->val;
        node->next = NULL;
    }
};