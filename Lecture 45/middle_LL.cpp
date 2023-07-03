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

// middle
void middle(Node *&head)
{
    Node *temp1 = head;
    Node *temp2 = head;

    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
        if(temp1->next == NULL)
        {
            temp2 = temp2->next;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    print(temp2);
}

int main()
{
    Node *head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    print(head);

    cout << "Middle: " << endl;
    middle(head);

    return 0;
}