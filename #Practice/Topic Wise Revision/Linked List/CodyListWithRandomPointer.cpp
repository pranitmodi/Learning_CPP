// 138
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == NULL)
            return head;

        Node *temp = head->next;
        Node *head2 = new Node(head->val);
        Node *temp1 = head2;

        while(temp != NULL)
        {
            Node *n1 = new Node(temp->val);
            temp1->next = n1;
            temp1 = temp1->next;

            temp = temp->next;
        }

        temp = head;
        temp1 = head2;

        while(temp != NULL)
        {
            Node *temp3 = temp1->next;
            temp1->next = temp->next;
            temp->next = temp1;
            temp = temp1->next;
            temp1 = temp3;
        }

        temp = head;
        while(temp != NULL)
        {
            Node *temp3 = temp->next->next;
            if(temp->random != NULL)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;

            temp = temp3;
        }

        temp = head;
        temp1 = temp->next;
        while(temp!= NULL)
        {
            temp->next = temp1->next;
            temp = temp->next;
            if(temp1->next == NULL)
                break;
            temp1->next = temp->next;
            temp1 = temp1->next;
        }

        return head2;
    }
};