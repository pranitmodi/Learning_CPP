// 374
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int guess(int mid)
    {
        // given in the question
    }
    int guessNumber(int n) 
    {
        int s = 1;
        int e = n;

        while(s<=e)
        {
            int mid = s +(e-s)/2;
            int d = guess(mid);

            if(d == 0)
                return mid;
            else if(d > 0)
                s = mid + 1;
            else
                e = mid - 1;
        }    

        return -1;
    }
};