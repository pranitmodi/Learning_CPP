#include <bits/stdc++.h> 
using namespace std;
class NQueue
{
    public:
        int n;
        int s;
        int *rear;
        int *arr;
        int *front;
        int *next;
        int free;
        NQueue(int n, int s)
        {
            this->n = n;
            this->s = s;
            free = 0;
            front = new int[n];
            rear = new int[n];

            for(int i=0; i<n; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[s];
            arr = new int[s];

            for(int i=0; i<s-1; i++)
            {
                next[i] = i+1;
            }
            next[s-1] = -1;
        }

        // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
        bool enqueue(int x, int m)
        {
            if(free == -1)
                return false;

            int i = free;
            arr[i] = x;
            free = next[i];

            if(front[m-1] == -1)
                front[m-1] = i;
            else
                next[rear[m-1]] = i;

            rear[m-1] = i;
            next[i] = -1;
            return true;
        }

        // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
        int dequeue(int m)
        {
            if(front[m-1] == -1)
                return -1;
            
            int i = front[m-1];

            if(i == rear[m-1])
            {
                rear[m-1] = -1;
                front[m-1] = -1;
            }
            else
            {
                front[m-1] = next[i];
            }

            next[i] = free;
            free = i;

            return arr[i];
        }
};