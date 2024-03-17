// 202 Happy Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) 
    {
        map<int,int> m;
        while(n>1)
        {
            int sum = 0;
            int n1 = n;
            while(n1!=0)
            {
                int d = n1%10;
                sum += (d*d);
                n1 = n1/10;
            }
            if(m.find(sum) != m.end())
                return false;
            m[sum]++;
            n = sum;
        }    

        if(n == 1)
            return true;
        return false;
    }
};