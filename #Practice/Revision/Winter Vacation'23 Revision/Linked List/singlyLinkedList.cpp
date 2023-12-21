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
void insert(int pos, Node *&head, int val)
{
    Node *n1 = new Node(val);
    if(pos == 1)
    {
        n1->next = head;
        head = n1;
    }
    else
    {
        int c = 1;
        Node *temp = head;
        while(temp->next != NULL && c < pos)
        {
            c++;
            temp = temp->next;
        }

        if(temp->next == NULL)
        {
            temp->next = n1;
        }
        else
        {
            n1->next = temp->next->next;
            temp->next = n1;
        }
    }
    cout << val << " Inserted!" << endl;
}
void print(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
int main()
{
    Node *head = new Node(14);
    print(head);

    insert(1,head,12);
    print(head);

    insert(4,head,72);
    print(head);

    insert(8,head,86);
    print(head);

    insert(5,head,77);
    print(head);

    insert(1,head,66);
    print(head);

}