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
    Node *okay = new Node(data);
    if(head == NULL)
    {
        head = okay;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = okay;
}

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
}

// mid node
Node* mid(Node *&head)
{
    if(head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while(fast->next != NULL)
    {
        fast = fast->next;
        if(fast->next == NULL)
            break;
        
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void insertAtHead(Node *&head, Node *&target)
{
    if(head == NULL)
    {
        head = target;
        head->next = NULL;
        return;
    }

    target->next = head;
    head = target;
}

bool palindrome_LL(Node *&head)
{
    Node *middle = mid(head);
    cout << "Middle element: " << middle->data << endl;
    Node *temp = middle->next;
    Node *head2 = NULL;

    while(temp->next != NULL)
    {
        Node *next1 = temp->next;
        insertAtHead(head2,temp);
        temp = next1;
    }
    insertAtHead(head2,temp);
    middle->next = NULL;

    cout << "First Half: ";
    print(head);
    cout << "Other Half: ";
    print(head2);


    if(head->data == head2->data)
    {
        while(head->next != NULL && head2->next != NULL)
        {
            if(head->data == head2->data)
            {
                head = head->next;
                head2 = head2->next;
            }
        }
        if(head->data == head2->data && head->next == NULL && NULL == head2->next)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *head = NULL;
    insert(head,4);
    insert(head,34);
    insert(head,4);
    insert(head,3);
    insert(head,3);
    insert(head,4);
    insert(head,34);
    insert(head,4);
    print(head);

    if(palindrome_LL(head))
        cout << "Palindrome!" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}