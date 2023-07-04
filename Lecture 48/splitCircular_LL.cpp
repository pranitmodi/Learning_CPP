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
            int value = this->data;
            if(this->next != NULL)
            {
                delete next;
                this->next = NULL;
            }
            cout << "Node has been deleted with data - " << value << endl;
        }
};

// traverse
void print(Node *&head)
{
    // if empty list
    if(head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }
    // printing the data in head, because loop stops when it is head again
    // can be done via DO-WHILE loop
    
    Node *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << endl;
}

// insert at any pos
void insertAtPos(Node *&head, int pos, int data)
{
    Node *temp = new Node(data);
    if(pos == 1)
    {
        //what if head is empty
        if(head == NULL)
        {
            head = temp;
            head->next = head; // important
        }
        else
        {
            if(head->next == head)
            {
                temp->next = head;
                head->next = temp;
                head = temp;
            }
            else
            {
                Node *con = head;
                while(con->next != head)
                {
                    con = con->next;
                }
                temp->next = head;
                con->next = temp;
                head = temp;
            }
        }
    }
    else
    {
        Node *con = head;
        int c=1;
        while(c < pos-1)
        {
            c++;
            con = con->next;
        }

        temp->next = con->next;
        con->next = temp;
    }
}

// split into two
void split(Node *&head, Node *&head1, Node *&head2)
{
    if(head == NULL)
        cout << "Empty!" << endl;

    Node *slow = head;
    Node *fast = head;

    while(fast->next != head)
    {
        fast = fast->next;
        if(fast->next == NULL)
            break;
        
        slow = slow->next;
        fast = fast->next;
    }

    cout << slow->data << endl;
    cout << fast->data << endl;

    Node *nex = slow->next;
    slow->next = head;
    fast->next = nex;

    head1 = head;
    head2 = nex;
}

// insert at head
void insertAtHead(Node *&head, int data)
{
    insertAtPos(head,1,data);
}
int main()
{

    Node *head = NULL;
    insertAtPos(head,1,23);
    insertAtPos(head,2,45);
    insertAtPos(head,3,98);
    insertAtPos(head,4,74);
    insertAtPos(head,5,36);
    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    print(head);

    Node *head1 = NULL;
    Node *head2 = NULL;

    split(head,head1,head2);
    print(head1);
    print(head2);

    return 0;
}