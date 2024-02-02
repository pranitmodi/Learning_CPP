// https://www.geeksforgeeks.org/problems/valid-substring0624/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMaxLen(string s) {
        int left = 0;
        int right = 0;
        int maxi = 0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
                
            if(left == right)
                maxi = max(maxi,2*left);
                
            if(right > left)
            {
                left = right = 0;
            }
        }
        
        left = right = 0;
        
        
        // for cases like (((()
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
                
            if(left == right)
                maxi = max(maxi,2*left);
                
            if(left > right)
            {
                left = right = 0;
            }
        }
        
        return maxi;
    }
};