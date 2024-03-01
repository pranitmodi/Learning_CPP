// 5
#include <bits/stdc++.h>
using namespace std;

// my solution
class Solution {
public:
    bool check(string s, int i, int w)
    {
        if((i-w)>=0 && (i+w)<s.length())
        {
            if(s[i-w] == s[i+w])
                return true;
        }
        return false;
    }
    string longestPalindrome(string s) 
    {
        int n = s.length();
        if(n==1)
            return s;

        int maxi = 1;
        string ans = s.substr(0,1);
        int i = 0;
        
        while(i<n-1)
        {
            if(i>0 && s[i-1] == s[i+1])
            {
                int cnt = 1;
                int w = 1;
                while(check(s,i,w))
                {
                    w++;
                    cnt += 2;
                }
                w--;
                if(cnt > maxi)
                {
                    maxi = cnt;
                    ans = s.substr(i-w,cnt);
                }
            }
            if(i<n-1 && s[i] == s[i+1])
            {
                int w = 1;
                int cnt = 2;
                int t = i+1;
                while((i-w>=0) && (i+w<n) && s[i-w] == s[t+w])
                {
                    cnt += 2;
                    w++;
                }
                w--;
                if(cnt>maxi)
                {
                    maxi = cnt;
                    ans = s.substr(i-w,cnt);
                }
            }
            i++;
        }
        return ans;
    }
};

// brute force - TLE
class Solution {
public:
    bool check(string s)
    {
        int i = 0;
        int j = s.length()-1;

        while(i<j)
        {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) 
    {
        int ans = 0;
        string str = "";
        for(int i=0; i<s.length(); i++)
        {
            int cnt = 1;
            for(int j=i; j<s.length(); j++)
            {
                cnt++;
                if(check(s.substr(i,cnt)))
                {
                    if(cnt > ans)
                    {
                        ans = cnt;
                        str = s.substr(i,cnt);
                    }
                }
            }
        }

        return str;
    }
};