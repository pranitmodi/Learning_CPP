#include <bits/stdc++.h>
using namespace std;
class Stack
{
    public:
        int size;
        int top;
        int *arr;

        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            this->top = -1;
        }

        void push(int ele)
        {
            if(size-top > 1)
            {
                top++;
                arr[top] = ele;
            }
            else
                cout << "Stack Overflow" << endl;
        }

        void pop()
        {
            if(top >= 0)
                top--;  
            else
                cout << "Empty Stack" << endl;
        }

        int peek()
        {
            if(top >= 0)
                return arr[top];
            else
            {
                cout << "Empty Stack" << endl;
                return -1;
            }
        }

        bool isEmpty()
        {
            if(top == -1)
                return true;
            else
                return false;
        }
};
int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);

    cout << s.peek() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    if(s.isEmpty())
        cout << "Empty Stack" << endl;
    else
        cout << "Not empty" << endl;

    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);
    s.push(3);

    return 0;
}