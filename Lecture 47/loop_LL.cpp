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
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        Node *temp2 = head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
void print(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != NULL);
        cout << endl;
    }
}

// Approach 1
bool detectLoopMaps(Node *&head)
{
    if(head == NULL)
        return false;
    
    map <Node*,bool> visited;
    Node *temp = head;

    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            cout << "Present on element: " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool detectLoopSlowFast(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if(fast == NULL)
            return false;
        fast = fast->next;

        if(slow == fast)
            return true;
    }
    while(fast != NULL);

    return false;
}

int main()
{
    Node *head = NULL;
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,8);
    insert(head,52);
    insert(head,16);
    insert(head,77);
    Node* temp = head->next;
    temp = temp->next;
    temp = temp->next;
    temp = temp->next;
    temp->next = head->next;
    // print(head);
    if(detectLoopMaps(head))
        cout << "Cycle is Present!" << endl;
    else
        cout << "Not Present." << endl;

    if(detectLoopSlowFast(head))
        cout << "Cycle is Present!" << endl;
    else
        cout << "Not Present." << endl;


    return 0;
}