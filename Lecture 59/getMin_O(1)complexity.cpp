#include <bits/stdc++.h>
using namespace std;
class SpecialStack 
{
    stack<int> s;
    int mini;

    public:
    
    void push(int data) 
    {
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini)
            {
                int val = (2 * data) - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop() 
    {
        if(s.empty())
            return -1;
        
        int data = s.top();
        if(data > mini)
        {
            s.pop();
            return data;
        }
        else
        {
            int prevmini = mini;
            int val = (2 * mini) - data;
            mini = val;
            s.pop();
            return prevmini;
        }
    }

    int top() 
    {
        if(s.empty())
            return -1;

        int curr = s.top();
        if(curr < mini)
        {
            return mini;
        }
        else
            return curr;
    }

    bool isEmpty() 
    {
        if(s.empty())
            return true;
        else
            return false;
    }

    int getMin()
    {
        if(s.empty())
            return -1;
        else
            return mini;
    }  
};