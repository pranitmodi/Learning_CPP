// 258. Add Digits
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int addDigits(int num) 
    {
        while(num >= 10)
        {
            int n = num;
            int sum = 0;
            while(n>0)
            {
                int d = n%10;
                sum += d;
                n = n/10;
            }
            num = sum;
        }    
        return num;
    }
};