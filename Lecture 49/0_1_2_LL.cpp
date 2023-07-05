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

        ~Node()
        {
            int val = this->data;
            if(this->next != NULL)
            {
                delete next;
                this->next = NULL;
            }
            cout << "Node has been deleted with data: " << val << endl;
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

    Node *t = head;
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
}

void print(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != NULL);

    cout << endl;
}

void sort012(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    Node *zero = NULL;
    Node *one = NULL;
    Node *two = NULL;

    Node *one_start = NULL;
    Node *two_start = NULL;

    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            if(zero == NULL)
            {
                zero = temp;
                head = temp;
            }
            else
            {
                zero->next = temp;
                zero = zero->next;
            }
            temp = temp->next;
            zero->next = NULL;
        }
        else if(temp->data == 1)
        {
            if(one == NULL)
            {
                one = temp;
                one_start = temp;
            }
            else
            {
                one->next = temp;
                one = one->next;
            }
            temp = temp->next;
            one->next = NULL;
        }
        else if(temp->data == 2)
        {
            if(two == NULL)
            {
                two = temp;
                two_start = temp;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
            two->next = NULL;
        }
    }
    zero->next = one_start;
    if(one_start == NULL)
        zero->next = two_start;
    else
        one->next = two_start;
}

int main()
{   
    Node *head = NULL;
    insert(head,2);
    insert(head,0);
    insert(head,0);
    insert(head,1);
    insert(head,1);
    insert(head,0);
    insert(head,2);
    insert(head,1);
    insert(head,2);
    insert(head,0);
    insert(head,0);
    print(head);

    cout << "Sorted LL: " << endl;
    sort012(head);
    print(head);

    return 0;
}