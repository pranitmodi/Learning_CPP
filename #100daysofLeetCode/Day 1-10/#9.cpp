// 409 Longest Palindrome
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int> v(52,0);
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                v[s[i] - 'a']++;
            else
                v[(s[i]-'A') + 26]++;
        }

        int ans = 0;
        int cnt = 0;
        for(int i=0; i<52; i++)
        {
            if(v[i] & 1)
                cnt++;
            ans += (2* (v[i]/2));
        }

        if(cnt>0)
            return ++ans;
        return ans;
    }
};