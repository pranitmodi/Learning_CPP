// 367
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1 - sum of odd numbers give perfect squares
    bool isPerfectSquare1(int num) 
    {
        int a = 1;
        long int sum = a;
        while(sum < num)
        {
            a += 2;
            sum += a;
        }

        if(sum == num)
            return true;
        return false;
    }

    // binary search
    bool isPerfectSquare(int num) 
    {
        int l = 0, r = num;
        long long int mid;
        while(l <= r) 
        {
            mid = (l+r)/2;
            if(mid*mid == num)
                return true;
            else if(mid*mid < num)
                l = mid+1;
            else
                r = mid-1;
        }
        return false;
    }
};