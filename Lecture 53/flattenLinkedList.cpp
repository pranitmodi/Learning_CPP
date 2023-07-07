#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node *child;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->child = NULL;
        }
};
void insert(Node *&head, int data)
{
    Node *next1 = new Node(data);
    if(head == NULL) 
    {
        head = next1;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = next1;
}
void insertChild(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        int n;
        cout << "Number of elements under " << temp->data << " : ";
        cin >> n;

        Node *ch = temp;
        int ele;
        cin >> ele;
        ch->child = new Node(ele);
        ch = ch->child;

        for(int i=2; i<=n; i++)
        {
            cin >> ele;
            ch->next = new Node(ele);
            ch = ch->next;
        }

        temp = temp->next;
    }
}
void print(Node *&head)
{
    if(head == NULL)
        return;
    
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        if(temp->next == NULL)
            break;
        
        temp = temp->next;
    }while(temp != NULL);
    cout << endl;
}

Node* merge2LL(Node* first, Node*second)
{
    // if(first == NULL)
    //     return second;

    // if(second == NULL)
    //     return first;

    Node* ans = new Node(-1);
    Node* final = ans;
    Node *temp1 = first;
    Node *temp2 = second;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data <= temp2->data)
        {
            ans->next = temp1;
            ans = ans->next;
            if(temp1->next == NULL)
            {
                temp1 = NULL;
                break;
            }
            temp1 = temp1->next;
        }
        else
        {
            ans->next = temp2;
            ans = ans->next;
            if(temp2->next == NULL)
            {
                temp2 = NULL;
                break;
            }
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL)
    {
        ans->next = temp1;
        ans = ans->next;
        if(temp1->next == NULL)
        {
            temp1 = NULL;
            break;
        }
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        ans->next = temp2;
        ans = ans->next;
        if(temp2->next == NULL)
        {
            temp2 = NULL;
            break;
        }
        temp2 = temp2->next;
    }
    print(final->next);
    return final->next;
}

Node* flatten(Node* head)
{
    // base condition
    if(head->next == NULL)
    {
        cout << head->data << endl;
        return head;
    }

    Node *second = flatten(head->next);
    head->next = head->child;
    Node *first = head;

    Node* ans = merge2LL(first,second);
    print(ans);

    return ans;
}

int main()
{
    Node *head = NULL;
    insert(head,1);
    insert(head,4);
    insert(head,7);
    insert(head,9);
    insert(head,10);
    insert(head,4);
    print(head);

    insertChild(head);
    Node *ans = flatten(head);

    print(ans);
    return 0;
}