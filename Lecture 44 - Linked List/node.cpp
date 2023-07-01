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
int main()
{
    // dynamic allocation
    Node *n1 = new Node(23);
    cout << n1->data << endl; //23
    cout << n1->next << endl; //0
}