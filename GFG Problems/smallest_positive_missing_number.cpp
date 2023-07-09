#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        vector<int> v(n+2,0);
        for(int i=0; i<n; i++)
        {
            if(arr[i] >= 0 && arr[i] <= n+1)
                v[arr[i]] = 1;
        }
        
        for(int i=1; i<=n+1; i++)
        {
            if(v[i] == 0)
                return i;
        }
    } 
};