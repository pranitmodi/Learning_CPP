#include <bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};

// APPROACH 1 = O(n^2)
bool check(petrolPump p[],int n, int k)
{
    int dif = 0;
    for(int i=k; i<n; i++)
    {
        if(dif<0)
            return false;
        dif = (dif + p[i].petrol) - p[i].distance;
    }
    for(int i=0; i<k; i++)
    {
        if(dif<0)
            return false;
        dif = (dif + p[i].petrol) - p[i].distance;
    }
    if(dif<0)
        return false;
    else
        return true;
}
int tour1(petrolPump p[],int n)
{
    int ans = -1;
    for(int i=0; i<n; i++)
    {
        if(p[i].petrol >= p[i].distance)
        {
            if(check(p,n,i))
                return i;
        }
    }
    return ans;
}

// APPROACH 2
int tour2(petrolPump p[],int n)
{
    int front = 0;
    int rear = 0;
    int d=0;
    
    while(rear <= n-1)
    {
        int bal = 0;
        do
        {
            bal = (bal + p[rear].petrol) - p[rear].distance;
            rear++;
            if(rear == n)
            {
                if(bal + d >= 0)
                    return front;
                else
                    return -1;
            }

            if(front == rear)
                return front;
        }
        while(bal >= 0);
            
        d = d + bal;
        front = rear;
    }
}