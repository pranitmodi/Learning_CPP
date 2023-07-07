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

// Calculating the Mid Node
Node* mid(Node*head)
{
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

// Merging the two halves
Node* merge(Node *first, Node *second)
{
    if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    // dummy node 
    Node *ans = new Node(-1);

    Node *temp = ans;
    while(first != NULL && right != NULL)
    {
        if(first->data < second->data)
        {
            temp->next = first;
            temp = temp->next;
            if(first->next == NULL)
            {
                first = NULL;
                break;
            }
            first = first->next;
        }
        else
        {
            temp->next = second;
            temp = temp->next;
            if(second->next == NULL)
            {
                second = NULL;
                break;
            }
            second = second->next;
        }
    }

    while(first != NULL)
    {
        temp->next = first;
        temp = temp->next;
        if(first->next == NULL)
        {
            first = NULL;
            break;
        }
        first = first->next;    
    }

    while(second != NULL)
    {
        temp->next = second;
        temp = temp->next;
        if(second->next == NULL)
        {
            second = NULL;
            break;
        }
        second = second->next;    
    }
    return ans->next;
}

// Merge Sort
Node* mergeSort(Node *head)
{
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    // splitting into two halves
    Node* middle = mid(head);
    Node *first = head;
    Node* second = middle->next;
    middle->next = NULL;

    // sorting the halves
    first = mergeSort(first);
    second = mergeSort(second);

    // Merge both left and right
    Node *result = merge(first, second);
    return result;
}

int main()
{
    Node *head = NULL;
    insert(head,4);
    insert(head,5);
    insert(head,4);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,1);
    print(head);

    cout << "Sorted: " << endl;
    Node *head1 = mergeSort(head);
    print(head1);

    return 0;
}