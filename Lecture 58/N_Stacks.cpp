#include <bits/stdc++.h> 
class NStack
{
    public:
        int s;
        int n;
        int *top;
        int *arr;
        int *next;
        int freespot;

        NStack(int N, int S)
        {
            s = S;
            n = N;
            top = new int[n];
            arr = new int[s];
            next = new int[s];
            freespot = 0;

            for(int i=0; i<n; i++)
            {
                top[i] = -1;
            }

            for(int i=0; i<s-1; i++)
            {
                next[i] = i+1;
            }
            next[s-1] = -1;
            
        }

        // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
        bool push(int x, int m)
        {
            if(freespot == -1)
                return false;

            // start with where the element needs to be inserted
            int index = freespot;
            arr[index] = x;

            freespot = next[index];
            next[index] = top[m-1];
            top[m-1] = index;

            return true;
        }

        // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
        int pop(int m)
        {
            if(top[m-1] == -1)
                return -1;
            
            // start with current top element index of the stack
            int index = top[m-1];
            top[m-1] = next[index];

            next[index] = freespot;
            freespot = index;

            return arr[index];
        }
};