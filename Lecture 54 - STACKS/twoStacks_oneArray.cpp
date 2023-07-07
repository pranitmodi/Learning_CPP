#include <bits/stdc++.h>
using namespace std;
class TwoStack
{
    public:
        int size;
        int top1;
        int top2;
        int *arr;

        // Initialize TwoStack.
        TwoStack(int s) 
        {
           this->size = s;
           arr = new int[size];
           top1 = -1;
           top2 = size;
        }
        
        // Push in stack 1.
        void push1(int num) 
        {
            if(top2 - top1 > 1)
            {
                top1++;
                arr[top1] = num;
            }
            else
            {
                cout << "Stack Overflow" << endl;
            }
        }

        // Push in stack 2.
        void push2(int num) 
        {
            if(top2 - top1 > 1)
            {
                top2--;
                arr[top2] = num;
            }
            else
            {
                cout << "Stack Overflow" << endl;
            }
        }

        // Pop from stack 1 and return popped element.
        int pop1() 
        {
            if(top1 == -1)
                return -1;
            else
                return arr[top1--];
        }

        // Pop from stack 2 and return popped element.
        int pop2() 
        {
            if(top2 == size)
                return -1;
            else
                return arr[top2++];
        }
};