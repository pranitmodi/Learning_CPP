// 232
#include<bits/stdc++.h>
using namespace std;
class MyQueue 
{
    public:
        stack<int> s1;
        stack<int> s2;
        MyQueue() {}
        
        void push(int x) 
        {
            while(!s2.empty())
            {
                int val = s2.top();
                s2.pop();
                s1.push(val);
            }    

            s1.push(x);

            while(!s1.empty())
            {
                int val = s1.top();
                s1.pop();
                s2.push(val);
            }
        }
        
        int pop() 
        {
            int val = -1;
            if(!s2.empty())
            {
                val = s2.top();
                s2.pop();
            }
            return val;
        }
        
        int peek() 
        {
            int val = -1;
            if(!s2.empty())
                val = s2.top();
            return val;
        }
        
        bool empty() 
        {
            return s2.empty();
        }
};