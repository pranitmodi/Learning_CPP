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

// void reverse
void reverse(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;

        while(temp != NULL)
        {
            Node *n = temp->next;
            temp->next = prev;
            prev = temp;
            temp = n;
        }
        
        head = prev;
    }
}

// using recursion
void reverseRecursion(Node *&head, Node *temp, Node *prev)
{

    if(temp == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = temp->next;
    temp->next = prev;
    prev = temp;
    temp = forward;

    reverseRecursion(head,temp,prev);
}
int main()
{
    Node *head = NULL;
    insert(head,23);
    insert(head,45);
    insert(head,96);
    insert(head,77);
    insert(head,52);
    insert(head,16);
    print(head);

    cout << "Reverse Linked List: " << endl;
    reverse(head);
    print(head);

    cout << "Reversed Again(recursively): " << endl;
    Node *prev = NULL;
    Node *temp = head;
    reverseRecursion(head,temp,prev);
    print(head);

    return 0;
}