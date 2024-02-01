// 84
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int maxi = 0;
        stack<int> l;
        stack<int> r;

        l.push(-1);
        vector<int> left(heights.size());
        for(int i=0; i<heights.size(); i++)
        {
            if(l.top() == -1)
                left[i] = -1;
            else
            {
                while(l.top()!=-1 && heights[l.top()] >= heights[i])
                {
                    l.pop();
                }
                left[i] = l.top();
            }
            l.push(i);
        }

        r.push(-1);
        vector<int> right(heights.size());
        for(int i=heights.size()-1; i>=0; i--)
        {
            if(r.top() == -1)
                right[i] = -1;
            else
            {
                while(r.top()!=-1 && heights[r.top()] >= heights[i])
                {
                    r.pop();
                }
                right[i] = r.top();
            }
            r.push(i);
        }

        for(int i=0; i<heights.size(); i++)
        {
            int le = left[i];
            int ri = right[i];

            if(ri == -1)
                ri = heights.size();

            int a = (ri-le-1) * heights[i];
            maxi = max(maxi,a); 
        }

        return maxi;
    }
};