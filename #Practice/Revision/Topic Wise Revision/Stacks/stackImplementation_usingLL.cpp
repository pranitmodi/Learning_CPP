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
            cout << "Deleted: " << val << endl;
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
            temp->next = top->next;
            top->next = temp;
        }

        int topEle()
        {
            if(top->next == NULL)
            {
                cout << "Stack Empty" << endl;
                return -1;
            }
            else
            {
                return top->next->data;
            }
        }

        void pop()
        {
            if(top->next == NULL)
            {
                cout << "Stack Empty" << endl;
            }
            else
            {
                Node *temp = top->next;

                if(temp->next == NULL)
                {
                    delete temp;
                    top->next = NULL;
                }
                else
                {
                    top->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                }
            }
        }
};
int main()
{
    Stack st;
    st.push(1);
    cout << st.topEle() << endl;
    st.push(23);
    cout << st.topEle() << endl;
    st.push(245);
    cout << st.topEle() << endl;
    
    st.pop();
    cout << st.topEle() << endl;
    st.pop();

    st.push(3);
    cout << st.topEle() << endl;
}