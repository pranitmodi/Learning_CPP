#include <bits/stdc++.h>
using namespace std;
class Node
{
    public: 
        int data;
        Node *next;
        Node *random;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};

void print(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;

    cout << "Pairing: " << endl;
    temp = head;
    while(temp != NULL)
    {
        cout << &*temp << " -> " << temp->data << " - " << temp->random->data << endl;

        if(temp->next == NULL)
            break;
        temp = temp->next;
    }
}

Node* clone(Node *&head)
{
    Node *head2 = new Node(head->data);
    Node *temp2 = head2;
    Node *temp1 = head->next;

    map<Node*,Node*> mapping;
    mapping[head] = head2;

    while(temp1 != NULL)
    {
        Node *next1 = new Node(temp1->data);
        temp2->next = next1;

        mapping[temp1] = next1;

        if(temp1->next == NULL)
            break;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    Node *temp = head;
    while(temp != NULL)
    {
        mapping[temp]->random = mapping[temp->random];

        if(temp->next == NULL)
            break;
        temp = temp->next;
    }
    return head2;
}

// Approach 2
Node* clone2(Node *head)
{
    Node *head2 = new Node(head->data);
    Node *temp1 = head->next;
    head->next = head2;
    Node *temp2 = head2;

    // creating the pattern
    while(temp1 != NULL)
    {
        Node *next2 = new Node(temp1->data);
        temp2->next = temp1;
        temp2 = next2;

        if(temp1->next == NULL)
        {
            temp1->next = temp2;
            break;
        }

        Node *next1 = temp1->next;
        temp1->next = temp2;
        temp1 = next1;
    }

    // assigning random pointers
    Node *temp = head;
    while(temp != NULL)
    {
        temp->next->random = temp->random->next;

        if(temp->next->next == NULL)
            break;

        temp = temp->next->next;
    }

    // fixing the traversal
    temp = head2;
    while(temp->next != NULL)
    {
        temp->next = temp->next->next;

        temp = temp->next;
    }

    return head2;

}

int main()
{
    Node *head1 = NULL;
    Node *temp1 = new Node(1);
    Node *temp2 = new Node(2);
    Node *temp3 = new Node(3);
    Node *temp4 = new Node(4);
    Node *temp5 = new Node(5);
    Node *temp6 = new Node(6);
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;

    temp1->random = temp3;
    temp3->random = temp5;
    temp5->random = temp2;
    temp4->random = temp3;
    temp2->random = temp1;
    temp6->random = temp3;
    head1 = temp1;
    print(head1);
    cout << endl;

    cout << "Cloned LL: " << endl;

    // APPROACH 1
    // Node *head2 = clone(head1);
    // print(head2);

    // APPROACH 2
    Node *head2 = clone2(head1);
    print(head2);
    return 0;
}