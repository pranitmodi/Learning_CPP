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
                this->next = NULL;
                delete next;
            }
            cout << "Node has been deleted with data: " << val << endl;
        }
};
void Reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = NULL;

    while(curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head = prev;
}