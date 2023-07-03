#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        ~Node()
        {
            int value = this->data;
            if(this->next != NULL)
            {
                delete next;
                this->next = NULL;
                cout << "Here! " << value << endl;
            }
            cout << "Deleted node with value - " << value << endl;
        }
};

// traversing the list
void print(Node *head)
{
    Node *temp = head;
    while(temp !=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// length of the list
int len(Node *head)
{
    int len = 0;
    Node *temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// insert at head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// insert at tail
void insertAtTail(Node *&tail, Node *&head, int data)
{
    Node *temp = new Node(data);
    if(tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// insert at a particular position
void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    Node *temp = new Node(data);

    // if we have to insert at head
    if(pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    int c = 1;
    Node *temp2 = head;
    while(c < pos-1)
    {
        temp2 = temp2->next;
        c++;
    }

    // checking if we are inserting at the tail
    if(temp2->next == NULL)
    {
        temp2->next = temp;
        temp->prev = temp2;
        tail = temp;
    }
    else
    {
        temp->next = temp2->next;
        temp2->next->prev = temp; //this also 
        temp2->next = temp;
        temp->prev = temp2;
    }
}

// deleting a node
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if(pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;              
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        int c=1;
        while(c < pos-1)
        {
            c++;
            temp = temp->next;
        }

        Node *temp2 = temp->next;

        // if we are deleting the tail
        if(temp2 == tail)
        {
            tail = temp;
            tail->next = NULL;
        }
        else
        {
            temp2->next->prev = temp;
            temp->next = temp2->next;
        }

        temp2->next = NULL;
        delete temp2;
    }
}

int main()
{
    // Node *node1 = new Node(23);
    // Node *head = node1;
    // Node *tail = node1;

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail,34);
    print(head);

    insertAtTail(tail,head,78);
    insertAtTail(tail,head,58);
    print(head);

    insertAtPosition(head,tail,1,12);
    print(head);
    insertAtPosition(head,tail,5,98);
    print(head);
    insertAtPosition(head,tail,5,70);
    print(head);

    deleteNode(head,tail,1);
    print(head);

    deleteNode(head,tail,3);
    print(head);

    deleteNode(head,tail,4);
    print(head);

    cout << endl;

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << "Length: " << len(head) << endl;
    return 0;
}