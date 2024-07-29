// 85
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> array)
    {
        vector<int> left(array.size());
        vector<int> right(array.size());
        int maxi = 0;

        stack<int> l;
        l.push(-1);
        for(int i=0; i<array.size(); i++)
        {
            while(l.top()!=-1 && array[l.top()]>=array[i])
                l.pop();
            left[i] = l.top();
            l.push(i);
        }

        stack<int> r;
        r.push(-1);
        for(int i=array.size()-1; i>=0; i--)
        {
            while(r.top()!=-1 && array[r.top()]>=array[i])
                r.pop();
            right[i] = r.top();
            r.push(i);
        }

        for(int i=0; i<array.size(); i++)
        {
            int le = left[i];
            int ri = right[i];

            if(ri == -1)
                ri = array.size();

            int ans = array[i] * (ri-le-1);
            maxi = max(ans,maxi);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int maxi = 0;
        vector<int> array(matrix[0].size(),0);
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                    array[j]++;
                else
                {
                    if(array[j] != 0)
                    {
                        array[j] = 0;
                    }
                }
            }
            int ans = maxArea(array);
            maxi = max(ans,maxi);
        }

        return maxi;
    }
};