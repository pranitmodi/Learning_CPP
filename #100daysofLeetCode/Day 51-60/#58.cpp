// 941. Valid Mountain Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = arr.size();
        if(l == 1)
            return false;

        int c = -1;
        for(int i=0; i<l-1; i++)
        {
            if(c == -1)
            {
                if(arr[i+1] > arr[i])
                    c = 0;
                else 
                    return false;
            }
            else if(c == 0)
            {
                if(arr[i+1] < arr[i])
                    c = 1;
                else if(arr[i+1] == arr[i])
                    return false;
            }
            else
            {
                if(arr[i+1] >= arr[i])
                    return false;
            }
        }
        if(c == 1)
            return true;
        return false;
    }
};