// 917. Reverse Only Letters
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        string ans = s;
        for(int i=0; i<s.length(); i++)
        {
            if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <='Z'))
                ans[i] = 'a';
        }

        int c = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            while(c<s.length() && ans[c]!='a')
                c++;
            if(c >= s.length())
                break;

            if((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <='Z'))
                ans[c++] = s[i];
        }

        return ans;
    }
};