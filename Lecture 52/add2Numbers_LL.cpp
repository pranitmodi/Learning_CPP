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

void reverse(Node *&head)
{
    Node *temp = head;
    Node *head1 = NULL;
    while(temp->next != NULL)
    {
        Node *next1 = temp->next;
        insertAtHead(head1,temp);
        temp = next1;
    }
    insertAtHead(head1,temp);
    head = head1;
}

Node* add(Node *&head1, Node *&head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
        
    Node *ans = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int counter = 0;

    while(temp1 != NULL && temp2 != NULL)
    {
        int a = temp1->data;
        int b = temp2->data;

        a = a + b + counter;
        counter = a/10;
        a = a%10;
        insert(ans,a);

        if(temp1->next == NULL || temp2->next == NULL)
            break;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout << "after 1: " << endl;
    print(ans);
    if(temp1->next != NULL)
    {
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
            int a = temp1->data;
            a = a + counter;
            counter = a/10;
            a = a%10;

            cout << a << endl;
            insert(ans,a);
            if(temp1->next == NULL)
            {
                if(counter != 0)
                {
                    insert(ans,counter);
                }
                reverse(ans);
                return ans;
            }
        }
        insert(ans,temp1->data);
    }
    else if(temp2->next != NULL)
    {
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
            int a = temp2->data;
            a = a + counter;
            counter = a/10;
            a = a%10;

            insert(ans,a);
            if(temp2->next == NULL)
            {
                if(counter != 0)
                {
                    insert(ans,counter);
                }
                reverse(ans);
                return ans;
            }
        }
        insert(ans,temp2->data);
    }
    else if(counter != 0)
    {
        insert(ans,counter);
    }
    reverse(ans);
    return ans;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    cout << "Enter the number of digits of first number: ";
    int n;
    cin >> n;

    cout << "Enter the digits: " << endl;
    for(int i=1; i<=n; i++)
    {
        int ele;
        cin >> ele;
        insert(head1,ele);
    }

    cout << "Enter the number of digits of second number: ";
    cin >> n;

    cout << "Enter the digits: " << endl;
    for(int i=1; i<=n; i++)
    {
        int ele;
        cin >> ele;
        insert(head2,ele);
    }

    cout << "List1: ";
    print(head1);
    cout << "List2: ";
    print(head2);

    reverse(head1);
    reverse(head2);

    cout << "Reverse List1: ";
    print(head1);
    cout << "Reverse List2: ";
    print(head2);

    cout << "Ans: ";
    Node *res = NULL;
    res = add(head1,head2);
    print(res);

    return 0;
}