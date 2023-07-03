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

// delete the node with this element
void deleteNode(Node *&head, int ele)
{
    if(head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    // deleting head
    if(head->data == ele)
    {
        Node *temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        if(temp == head)
            head = NULL;
        else
        {
            Node *temp2 = head;
            temp->next = head->next;
            head = head->next;

            temp2->next = NULL;
            delete temp2;
        }
    }
    else if(head->next == head)
    {
        cout << "not found!" << endl;
    }
    else
    {
        int found = 1;
        Node *temp = head;
        while(temp->next->data != ele)
        {
            temp = temp->next;
            if(temp == head)
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
        {
            Node *temp2 = temp->next;
            temp->next = temp2->next;

            temp2->next = NULL;
            delete temp2;
        }
        else
        {
            cout << "Not Found!" << endl;
        }
    }
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
    print(head);
    insertAtPos(head,2,45);
    print(head);
    // insertAtPos(head,3,98);
    // print(head);
    // insertAtPos(head,4,74);
    // print(head);
    // insertAtPos(head,5,36);
    // print(head);
    // insertAtHead(head,9);
    // print(head);
    // insertAtHead(head,8);
    // print(head);
    // insertAtHead(head,7);
    // print(head);
    // insertAtHead(head,6);
    // print(head);

    cout << endl << "deletion starts: " << endl;

    deleteNode(head, 23);
    print(head);
    deleteNode(head, 63);
    print(head);
    // deleteNode(head, 100);
    // print(head);
    return 0;
}