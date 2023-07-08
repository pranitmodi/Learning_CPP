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
class Stack
{
    public:
        Node *top;

        Stack()
        {
            top = new Node(-1);
        }

        void push(int data)
        {
            Node *temp = new Node(data);
            temp->next = top;
            top = temp;
        }

        int pop()
        {
            int ele = top->data;
            if(ele == -1)
            {
                cout << "Empty Stack" << endl;
                return -1;
            }
            else
            {
                Node *temp = top;
                top = top->next;
                temp->next = NULL;
                delete temp;
                return ele;
            }
        }

        void isEmpty()
        {
            if(top->data == -1)
                cout << "Empty Stack" << endl;
            else
                cout << "Not an empty stack" << endl;
        }

        int peek()
        {
            if(top->data == -1)
            {
                cout << "Empty Stack" << endl;
                return -1;
            }
            else
            {
                return top->data;
            }
        }

        void display()
        {
            if(top->data == -1)
            {
                cout << "Empty Stack" << endl;
                return;
            }

            Node *temp = top;
            while(temp->data != -1)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }


};
int main()
{
    Stack s;
    s.display();

    s.push(6);
    s.push(6);
    s.push(6);
    s.display();

    s.pop();
    s.pop();
    s.display();

    cout << "Top elements is: " << s.peek() << endl;
    s.pop();
    s.pop();
    s.display();
    return 0;
}