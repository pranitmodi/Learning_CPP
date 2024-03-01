// 8
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int n = s.length();

        while(i<n && (s[i] == ' '))
            i++;

        int neg = 0;
        if(s[i] == '-')
        {
            neg = 1;
            i++;
        }
        else if(s[i] == '+')
            i++;

        while(i<n && (s[i] == '0'))
            i++;

        long int ans = 0;
        while(s[i]>='0' && s[i]<='9')
        {
            ans = (ans*10) + ((int)s[i] - 48);
            if(ans > INT_MAX)
                break;
            i++;
        }

        if(ans>INT_MAX)
        {
            if(neg)
                return INT_MIN;
            return INT_MAX;
        }

        if(neg)
            return -1*ans;
        return ans;
    }
};