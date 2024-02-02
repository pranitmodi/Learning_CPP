#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/longest-prefix-also-suffix/
class Solution
{
  public:		
	int lps(string s) 
    {
	    int n = s.size();
        int i = n-2;
        int j = n-1;
        int cnt = 3;
        while(i >= 0)
        {
            if(s[i] == s[j])
            {
                i--;
                j--;
            }
            else
            {
                // cnt is to keep track of i.
                i = n-cnt;
                cnt++; // this is to keep i on track, beacuse when s[i] == s[j], this will change.
                j = n-1; //keep this at last index only untill in cotinous all characters start occuring
            }
        }
        return n-j-1;
	}
};