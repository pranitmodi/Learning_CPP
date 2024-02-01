// 1544
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(char c1, char c2)
    {
        if(tolower(c1) == tolower(c2))
        {
            int a = c1;
            int b = c2;
            if(((a>=65 && a<=90) && (b>=97 && b<=122)) || ((b>=65 && b<=90) && (a>=97 && a<=122)))
                return true;
        }
        return false;
    }
    string makeGood(string s) 
    {
        if(s == "")
            return s;

        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.length(); i++)
        {
            char ch = s[i];
            while(!st.empty() && check(st.top(),ch))
            {
                st.pop();
                if(i == s.length()-1)
                {
                    ch = '@';
                    break;
                }
                ch = s[++i];
            }
            if(ch == '@')
                break;
            st.push(ch);
        }    

        string w = "";
        while(!st.empty())
        {
            w = st.top() + w;
            st.pop();
        }

        return w;
    }
};