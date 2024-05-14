// 1122. Relative Sort Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        map<int,int> m;
        vector<int> m1;
        for(int i=0; i<arr2.size(); i++)
            m[arr2[i]]++;

        for(int i=0; i<arr1.size(); i++)
        {
            if(m.find(arr1[i]) != m.end())
                m[arr1[i]]++;
            else
                m1.push_back(arr1[i]);
        }

        int w = 0;
        for(int i=0; i<arr2.size(); i++)
        {
            int s = m[arr2[i]];
            while(s>1)
            {
                arr1[w++] = arr2[i];
                s--;
            }
        }

        sort(m1.begin(),m1.end());
        for(int i=0; i<m1.size(); i++)
        {
            arr1[w++] = m1[i];
        }

        return arr1;
    }
};