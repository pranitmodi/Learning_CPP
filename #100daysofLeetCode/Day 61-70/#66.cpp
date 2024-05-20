// 1394. Find Lucky Integer in an Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int ans = -1;
        int maxi = 0;
        int sum = 1;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i] == arr[i-1])
                sum++;
            else
            {
                if(sum >= maxi && sum == arr[i-1])
                {
                    maxi = sum;
                    ans = arr[i-1];
                }
                sum = 1;
            }
        }
        if(sum >= maxi && sum == arr[arr.size()-1])
        {
            maxi = sum;
            ans = arr[arr.size()-1];
        }
        return ans;
    }
};