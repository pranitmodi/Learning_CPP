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
void reverse(Node *&head1, Node *&head, Node *&pre, Node *&tail)
{
    Node *prev = tail->next;
    Node *curr = head1;

    while(prev != tail)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    if(head1 == head)
    {
        head = tail;
    }
    else
    {
        pre->next = tail;
    }
    cout << "Iteration: ";
    print(head);
}

void kReverse(Node *&head, int k)
{
    Node *temp = head;
    Node *temp2 = head;
    Node *pre = head;
    while(temp->next != NULL)
    {
        for(int i=1; i<k; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                return;
            // cout << "t: " << temp->data << endl;
        }
        // cout << "head: " << temp2->data << endl;
        // cout << "tail: " << temp->data << endl;
        if(temp->next == NULL)
        {
            reverse(temp2,head,pre,temp);
            return;
        }
        reverse(temp2,head,pre,temp);
        pre = temp2;
        temp2 = temp2->next;
        temp = temp2;
    }
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
    print(head);

    kReverse(head,7);
    cout << "Final: ";
    print(head);
    cout << endl;

    return 0;
}