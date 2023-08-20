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
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }


}
int main()
{
    Node *head = new Node(23);
    Node *temp = NULL;

    cout << head->data << endl;
    cout << temp->data << endl;

    head = temp->next;

    cout << head->data << endl;
    cout << temp->data << endl;

}