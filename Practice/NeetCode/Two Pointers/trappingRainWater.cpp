// LeetCode HARD - 42
#include <bits/stdc++.h>
using namespace std;

// Approach 1
int trap(vector<int>& height) 
{
    stack<int> s;
    vector<int> left(height.size());
    vector<int> right(height.size());
    s.push(-1);
    for(int i=0; i<height.size(); i++)
    {
        if(s.top() > height[i])
        {
            left[i] = s.top();
        }
        else
        {
            while(s.top() <= height[i] && s.top() != -1)
            {
                s.pop();
            }
            left[i] = s.top();
            s.push(height[i]);
        }
    }
    s = stack<int>();
    s.push(-1);
    for(int i=height.size()-1; i>=0 ; i--)
    {
        if(s.top() > height[i])
        {
            right[i] = s.top();
        }
        else
        {
            while(s.top() <= height[i] && s.top() != -1)
            {
                s.pop();
            }
            right[i] = s.top();
            s.push(height[i]);
        }
    }

    int ans = 0;
    for(int i=0; i<height.size(); i++)
    {
        if(left[i] != -1 && right[i] != -1)
        {
            int val = min(left[i],right[i]) - height[i];
            ans += val;
        } 
    }
    return ans;
}

// Approach 2 - More Optimised
// We need the maximum value for each point left and right, and minimum of these two
// if any side bigger number is not present the store -1
int trap(vector<int>& height) 
{
    vector<int> h(height.size());
    int left = -1;
    int right = -1;
    for(int i=0; i<height.size(); i++)
    {
        if(left > height[i])
            h[i] = left;
        else
            h[i] = -1;

        if(height[i] > left)
            left = height[i];
    }
    
    for(int i=height.size()-1; i>=0; i--)
    {
        if(right > height[i])
        {
            if(right < h[i] && h[i] != -1)
                h[i] = right;
        }
        else
            h[i] = -1;
            
        if(height[i] > right)
            right = height[i];
    }

    int ans = 0;
    for(int i=0; i<height.size(); i++)
    {
        if(h[i] != -1)
        {
            int val = h[i] - height[i];
            ans += val;
        } 
    }
    return ans;
}