#include <bits/stdc++.h>
using namespace std;
class Node
{
    public: 
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};
void insert(Node *&head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        Node *temp2 = head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
void print(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != NULL);
        cout << endl;
    }
}

// Approach
Node* firstNode(Node *&head)
{
    if(head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    // Floyd's Cycle Detection 
    do
    {
        slow = slow->next;
        fast = fast->next;
        if(fast == NULL)
            return fast;
        fast = fast->next;
    }
    while(slow != fast);

    // for the first node
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Removing the loop
void removeLoop(Node *&start)
{
    Node *temp = start;
    while(temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    Node *head = NULL;
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,8);
    insert(head,52);
    insert(head,16);
    insert(head,77);
    Node* temp = head->next;
    temp = temp->next;
    temp = temp->next;
    temp = temp->next;
    temp = temp->next;
    temp = temp->next;
    temp->next = head->next;
    // print(head);
    
    Node *ans = firstNode(head);
    if(ans == NULL)
    {
        cout << "No loop present." << endl;
    }
    else
    {
        cout << "Element at the first node: " << ans->data << endl;
        removeLoop(ans);
        cout << "Without the Loop: " << endl;
        print(head);
    }

    return 0;
}