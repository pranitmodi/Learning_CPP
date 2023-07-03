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

// correct only hopefully, but it was showing TLE
bool isCircular(Node* head)
{
    if(head == NULL)
        return true;
    Node *temp = head->next;
    while(temp != head)
    {
        if(temp == NULL)
            return false;
        temp = temp->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    
    return 0;
}