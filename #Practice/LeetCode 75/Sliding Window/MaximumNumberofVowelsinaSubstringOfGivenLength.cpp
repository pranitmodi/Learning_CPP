// 1456
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;

        return false;
    }
    int maxVowels(string s, int k) 
    {
        int maxi = 0;
        int curr = 0;
        for(int i=0; i<k; i++)
        {
            if(check(s[i]))
                curr++;
        }    

        maxi = curr;

        for(int i=1; i<(s.length()-k+1); i++)
        {
            if(check(s[i-1]))
                curr--;

            if(check(s[i+k-1]))
                curr++;

            maxi = max(maxi,curr);
        }

        return maxi;
    }
};