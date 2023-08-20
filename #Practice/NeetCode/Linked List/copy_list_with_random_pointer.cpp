// leetCode - 138
#include <bits/stdc++.h>
using namespace std;
class Node 
{
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) 
        {
            val = _val;
            next = NULL;
            random = NULL;
        }
};
Node* copyRandomList(Node* head) 
{
    if(head == NULL)
        return head;

    // Duplicating with just next pointers
    Node *temp = head->next;
    Node *head1 = new Node(head->val);
    Node *temp2 = head1;
    while(temp != NULL)
    {
        Node *t = new Node(temp->val);
        temp2->next = t;
        temp2 = temp2->next;

        temp = temp->next;
    }

    // creating the pattern with next pointers
    temp = head;
    temp2 = head1;
    while(temp != NULL)
    {
        Node *temp3 = temp2->next;
        temp2->next = temp->next;
        temp->next = temp2;

        temp = temp2->next;
        temp2 = temp3;
    }

    // assigning random pointers
    temp = head;
    while(temp != NULL)
    {
        if(temp->random == NULL)
            temp->next->random = NULL;
        else
            temp->next->random = temp->random->next;

        if(temp->next->next == NULL)
            break;

        temp = temp->next->next;
    }

    // fixing the next pointers
    temp = head;
    temp2 = head1;
    while(temp != NULL)
    {
        if(temp2->next == NULL)
            break;
        Node *temp3 = temp2->next->next;
        temp->next = temp2->next;
        temp2->next = temp3;

        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    return head1;
}