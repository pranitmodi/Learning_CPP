#include <bits/stdc++.h> 
using namespace std;
class Deque
{
    public:
        int s;
        int front;
        int rear;
        int *arr;

        Deque(int n)
        {
            s=n;
            arr = new int[s];
            front = -1;
            rear = -1;
        }

        // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
        bool pushFront(int x)
        {
            if((front == 0 && rear == s-1) || front-1 == rear)
                return false;
            if(front == -1)
            {
                arr[0] = x;
                front = 0;
                rear = 0;
            }
            else
            {
                if(front == 0)
                    front = s-1;
                else
                    front--;

                arr[front] = x;
            }
            return true;
        }

        // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
        bool pushRear(int x)
        {
            if((front == 0 && rear == s-1) || rear+1 == front)
                return false;
            if(rear == -1)
            {
                arr[0] = x;
                front = 0;
                rear = 0;
            }
            else
            {
                if(rear == s-1)
                    rear = 0;
                else
                    rear++;
                arr[rear] = x;
            }
            return true;
        }

        // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
        int popFront()
        {
            if(front == -1)
                return -1;
            else
            {
                int val = arr[front];
                if(front == rear)
                {
                    front = -1;
                    rear = -1;
                    return val;
                }
                arr[front] = -1;
                front++;
                if(front == s)
                    front = 0;
                return val;
            }
        }

        // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
        int popRear()
        {
            if(rear == -1)
                return -1;
            else
            {
                int val = arr[rear];
                if(front == rear)
                {
                    front = -1;
                    rear = -1;
                    return val;
                }
                arr[rear] = -1;
                if(rear == 0)
                    rear = s-1;
                else
                    rear --;
                return val;
            }
        }

        // Returns the first element of the deque. If the deque is empty, it returns -1.
        int getFront()
        {
            if(front == -1)
                return -1;
            else
                return arr[front];
        }

        // Returns the last element of the deque. If the deque is empty, it returns -1.
        int getRear()
        {
            if(rear == -1)
                return -1;
            else
                return arr[rear];
        }

        // Returns true if the deque is empty. Otherwise returns false.
        bool isEmpty()
        {
            if(front == -1)
                return true;
            else
                return false;
        }

        // Returns true if the deque is full. Otherwise returns false.
        bool isFull()
        {
            if((rear + 1) % s == front)
                return true;
            else
                return false;
        }

        void print()
        {
            for(int i=0; i<s; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main()
{
    Deque d1(4);
    cout << d1.pushFront(5) << endl;
    d1.print();
    cout << d1.pushRear(47) << endl;
    d1.print();
    cout << d1.getRear() << endl;
    cout << d1.pushFront(47) << endl;
    cout << d1.pushFront(1) << endl;
    d1.print();
    cout << d1.getFront() << endl;
    cout << d1.pushFront(30) << endl;
    d1.print();
    cout << d1.pushRear(47) << endl;
    d1.print();
    cout << d1.isFull() << endl;
    cout << d1.getFront() << endl;
    cout << d1.getRear() << endl;

    return 0;
}