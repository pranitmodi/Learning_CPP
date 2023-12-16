#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    // better method
    bool isSubsequence(string s, string t) 
    {
        int j = 0;

        for(int i = 0; i < t.size(); i++) {
            if(t[i] == s[j]) {
                j++;
            }
        }
        return (j == s.size());
    }

    // my complicated method using recursion, works but
    bool check(string s, string t)
    {
        if(t == "")
            return false;

        int sn = s.length();
        int tn = t.length();

        if(s[0] == t[0] && sn == 1)
            return true;

        if(s[0] == t[0] && sn > 1)
            return(check(s.substr(1,sn),t.substr(1,tn)));
        
        return(check(s,t.substr(1,tn)));
    }
    bool isSubsequence(string s, string t) {
        if(s == "")
            return true;

        return check(s,t);
    }
};