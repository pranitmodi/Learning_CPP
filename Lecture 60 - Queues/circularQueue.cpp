#include <bits/stdc++.h> 
using namespace std;
class CircularQueue
{
    public:
        int front;
        int rear;
        int *arr;
        int n;
        CircularQueue(int n)
        {
            this->n = n;
            front = -1;
            rear = 0;
            arr = new int[n];
        }

        // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
        bool enqueue(int value)
        {
            if(front == -1)
            {
                arr[rear] = value;
                front = rear;
                rear++;
                return true;
            }
            else if(front == rear)
                return false;
            else
            {
                arr[rear] = value;
                rear++;
                if(rear == n)
                    rear = 0;
            }
        }

        // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
        int dequeue()
        {
            if(front == -1)
                return -1;
            else
            {
                int val = arr[front];
                arr[front] = -1;
                front++;
                if(front == n)
                {
                    front = 0;
                }
                if(front == rear)
                {
                    front = -1;
                }

                return val;
            }
        }
};