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

        //destructor
        ~Node()
        {
            int value = this->data;
            //memory free
            if(this->next != NULL)
            {
                this->next = NULL; //ensures that any further attempts to access this->next will result in a null pointer
                delete next; //memory that was allocated for the object is freed
            }
            cout << "Memory is free for the node with data: " << value << endl;
        }
};

// shifting head backwards
void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);

    temp->next = head;
    head = temp;
}

// shifting tail forward
void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
}

// inserting at any position 
void InsertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    // Insert at start
    if(pos == 1)
    {
        InsertAtHead(head, data);
        return;
    }

    // Insert at the middle
    int c = 1;
    Node *temp = head;

    while(c < pos-1)
    {
        temp = temp->next;
        c++;

        // Insert at the end
        if(temp->next == NULL)
        {
            InsertAtTail(tail,data);
            return;
        }
    }

    Node *new1 = new Node(data);
    new1->next = temp->next;
    temp->next = new1;
}

// prints in forward manner only
void print(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DeleteNode(int pos, Node *&head, Node *&tail)
{
    if(pos == 1)
    {
        Node *temp = head;
        head = head->next;
        return;
        temp->next = NULL;
        delete temp;
    }

    int c = 1;
    Node *temp = head;
    while(c < pos-1)
    {
        temp = temp->next;
        c++;
    }

    Node *temp2 = temp->next;
    if(temp2 == tail)
    {
        temp->next = NULL;
        tail = temp;
    }
    else
    {
        temp->next = temp2->next;
    }
    temp2->next = NULL;
    delete temp2; //removing from the memory
}

int main()
{
    Node *new1 = new Node(18);

    Node *head = new1;
    // print(head);
    InsertAtHead(head,344);
    // print(head);
    InsertAtHead(head,346);
    // print(head);
    InsertAtHead(head,348);
    // print(head);
    InsertAtHead(head,350);
    print(head);

    Node *tail = new1;
    // print(head);
    // InsertAtTail(tail,344);
    // print(head);
    // InsertAtTail(tail,346);
    // print(head);
    // InsertAtTail(tail,348);
    // print(head);
    // InsertAtTail(tail,350);
    // print(head);

    InsertAtPosition(head,tail,2,666);
    InsertAtPosition(head,tail,4,6786);
    InsertAtPosition(head,tail,1,0);
    InsertAtPosition(head,tail,9,45);
    InsertAtPosition(head,tail,45,545);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << "Deletion Starts: " << endl;
    DeleteNode(2,head,tail);
    print(head);
    DeleteNode(1,head,tail);
    print(head);
    DeleteNode(3,head,tail);
    print(head);
    DeleteNode(7,head,tail);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;


    return 0;
}