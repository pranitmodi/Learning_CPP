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
class Queue 
{
    public:
        Node *qfront = NULL;
        Node *rear = NULL;

        /*----------------- Public Functions of Queue -----------------*/

        bool isEmpty() 
        {
            if(qfront == NULL)
                return true;
            else
                return false;
        }

        void enqueue(int data) 
        {
            Node *temp = new Node(data);
            if(qfront == NULL)
            {
                qfront = temp;
                rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = temp;
            }
        }

        int dequeue() 
        {
            if(qfront == NULL)
                return -1;
            else
            {
                Node *temp = qfront;
                int val = qfront->data;
                if(qfront->next == NULL)
                {
                    qfront = NULL;
                }
                else
                {
                    qfront = qfront->next;
                }
                temp->next = NULL;
                delete temp;
                return val;
            }
        }

        int front() 
        {
            if(qfront == NULL)
                return -1;
            else
                return qfront->data;
        }
};