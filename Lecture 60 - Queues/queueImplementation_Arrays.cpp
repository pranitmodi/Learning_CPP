#include <bits/stdc++.h>
using namespace std;
class Queue 
{
    public:
        int *arr;
        int s;
        int qfront;
        int rear;
        Queue() 
        {
            s = 100001;
            arr = new int[s];
            qfront = 0;
            rear = 0;
        }

        /*----------------- Public Functions of Queue -----------------*/

        bool isEmpty() 
        {
            if(qfront == rear)
                return true;
            else
                return false;
        }

        void enqueue(int data) 
        {
            if(rear == (s-1))
                return;
            else
            {
                arr[rear] = data;
                rear++;
            }
        }

        int dequeue() 
        {
            if(qfront == rear)
            {
                return -1;
            }
            else
            {
                int val = arr[qfront];
                arr[qfront] = -1;
                qfront++;
                if(qfront == rear)
                {
                    qfront = 0;
                    rear = 0;
                }
                return val;
            }
        }

        int front() 
        {
            if(qfront == rear)
                return -1;
            return arr[qfront];
        }
};