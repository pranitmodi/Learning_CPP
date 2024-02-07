// 155
#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {}
    
    void push(int val) 
    {
        if(st.empty())
            st.push(make_pair(val,val));
        else
        {
            pair<int,int> p = st.top();
            int mini = p.second;

            mini = min(mini,val);
            st.push(make_pair(val,mini));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// Another approach for SC-O(1)
class MinStack {
public:
    int mini;
    stack<int> st;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) 
    {
        if(st.empty())
        {
            st.push(val);
            mini = val;
        }    
        else
        {
            if(val < mini)
            {
                int d = (2*val) - mini; // IMPORTANT PART
                mini = val;
                st.push(d);
            }
            else
                st.push(val);
        }
    }
    
    void pop() 
    {
        if(st.empty())
            return;
        else
        {
            if(mini > st.top())
            {
                int d = (2*mini) - st.top(); // same over here
                mini = d;
                st.pop();
            }
            else
                st.pop();
        }    
    }
    
    int top() {
        if(!st.empty())
            return st.top();
        else
            return -1;
    }
    
    int getMin() {
        if(!st.empty())
            return mini;
        else 
            return -1;
    }
};