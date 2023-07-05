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

// merge 2 sorted LL
void merge(Node *&final, Node *&temp1, Node *&temp2)
{
    // if anyone of them is empty
    if(temp1 == NULL)
    {
        final = temp2;
        return;
    }
    if(temp2 == NULL)
    {
        final = temp1;
        return;
    }

    Node *head = NULL;
    // for initial node at head
    if((temp1->data) <= (temp2->data)) 
    {
        head = temp1;
        temp1 = temp1->next;
        final = head;
    }
    else
    {
        head = temp2;
        temp2 = temp2->next;
        final = head;
    }

    // rest of the nodes until condition holds true
    while(temp1->next != NULL || temp2->next != NULL)
    {
        if((temp1->data) <= (temp2->data)) 
        {
            head->next = temp1;
            head = head->next;
            if(temp1->next == NULL)
                break;
            temp1 = temp1->next;
        }
        else
        {
            head->next = temp2;
            head = head->next;
            if(temp2->next == NULL)
                break;
            temp2 = temp2->next;
        }
    }

    // if temp1 is longer than temp2
    while(temp1->next != NULL)
    {
        head->next = temp1;
        temp1 = temp1->next;
        head = head->next;
    }

    // vice-versa
    while(temp2->next != NULL)
    {
        head->next = temp2;
        temp2 = temp2->next;
        head = head->next;
    }

}

// Approach 2 - NEEDS TO BE FIXED
Node* solve(Node* first, Node* second) 
{
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }   

    Node *one = first;
    Node *one_next = one->next;
    Node *two = second;

    while(one->next != NULL && two != NULL)
    {
        int val = two->data;
        if((one->data <= val) && (one_next->data >= val))
        {
            if(two->next == NULL)
            {
                one->next = two;
                two->next = one_next;
                break;
            }
            Node *two_next = two->next;
            one->next = two;
            two->next = one_next;
            one = two;
            two = two_next;
        }
        else
        {
            one = one->next;
            if(one_next->next == NULL)
            {
                one->next = two;
                return first;
            }
            one_next = one_next->next;
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> data <= second -> data )
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
    
}

int main()
{   
    Node *head1 = NULL;
    Node *head2 = NULL;
    insert(head1,2);
    insert(head1,6);
    insert(head1,7);
    insert(head1,8);
    insert(head1,10);
    insert(head2,1);
    insert(head2,2);
    insert(head2,4);
    insert(head2,5);
    insert(head2,11);
    insert(head2,17);
    
    print(head1);
    print(head2);

    cout << "Sorted Array after merging: " << endl;
    Node *head = NULL;
    // merge(head,head1,head2);
    // print(head);

    head = sortTwoLists(head1,head2);
    print(head);

    return 0;
}