#include <bits/stdc++.h>
using namespace std;
class NQueue
{
    public:
        int free;
        int *front;
        int *rear;
        int *arr;
        int *next;

        int s;
        int k;

        NQueue(int N, int K)
        {
            s = N;
            k = K;
            arr = new int[s];
            next = new int[s];

            front = new int[k];
            rear = new int[k];
            free = 0;

            for(int i=0; i<s-1; i++)
            {
                next[i] = i+1;
            }
            next[s-1] = -1;

            for(int i=0; i<k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }
        }

        bool enqueue(int x, int m)
        {
            if(free == -1)
                return false;
            
            int index = free;
            free = next[index];

            arr[index] = x;

            if(front[m-1] == -1) // m-1 beacuse array index starts from 0.
            {
                front[m-1] = index;
            }
            else
            {
                // because we have to traverse from front to rear
                // thus next should be only updated when, a new element is pushed
                next[rear[m-1]] = index; 
            }
            
            // as soon as next = -1, we have reached our last index
            next[index] = -1;
            rear[m-1] = index;

            return true;
        }

        int pop(int m)
        {
            if(front[m-1] == -1)
                return -1;

            int index = front[m-1];

            front[m-1] = next[index];

            next[index] = free;
            free = index;

            return arr[index];
        }
};
int main()
{

    return 0;
}