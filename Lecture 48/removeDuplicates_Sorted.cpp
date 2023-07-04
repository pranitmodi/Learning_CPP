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

// Remove Duplicates
void removeDuplicates(Node *&head)
{
    if(head == NULL)
    {
        return;
    }
    Node *temp = head;
    while(temp->next != NULL)
    {
        int d = temp->data;
        Node *store = temp;
        temp = temp->next;
        while(temp->data == d)
        {   
            Node *curr = temp;
            temp = temp->next;

            // deletion part
            curr->next = NULL;
            delete curr;
        }
        store->next = temp;
    }

}

int main()
{   
    Node *head = NULL;
    insert(head,3);
    insert(head,3);
    insert(head,8);
    insert(head,8);
    insert(head,8);
    insert(head,9);
    insert(head,9);
    insert(head,10);
    print(head);

    removeDuplicates(head);
    print(head);

    return 0;
}