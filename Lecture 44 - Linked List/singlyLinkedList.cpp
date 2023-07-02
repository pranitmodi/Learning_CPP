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
                delete next; //memory that was allocated for the object is freed
                this->next = NULL; //ensures that any further attempts to access this->next will result in a null pointer
            }
            cout << "Memory is free for the node with data: " << value << endl;
        }
};
void InsertAtHead(Node *&head, int data) // shifting head backwards
{
    Node *temp = new Node(data);

    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int data) // shifting tail forward
{
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
}
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
void print(Node *&head) // prints in forward manner only
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

void DeleteNode(int pos, Node *&head)
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
    temp->next = temp2->next;
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
    DeleteNode(2,head);
    print(head);
    DeleteNode(1,head);
    print(head);
    DeleteNode(3,head);
    print(head);


    return 0;
}