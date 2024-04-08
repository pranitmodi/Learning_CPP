// 172. Factorial Trailing Zeroes
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // long long int fact(int n)
    // {
    //     if(n == 1)
    //         return 1;
    //     return (n * fact(n-1));
    // }
    int trailingZeroes(int n) 
    {
        int count = 0;
        for (long long i = 5; (n / i)>0; i *= 5)
        {
            count += (n / i);
        }
        return count;

        // if(n == 0)  
        //     return 0;
        // long long int f = fact(n);
        // int count = 0;
        // while(f!=0)
        // {
        //     int d = f%10;
        //     if(d != 0)
        //         break;
        //     count++;
        //     f = f/10;
        // }   
        // return count;
    }
};