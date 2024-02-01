// 1021
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        if(s == "")
            return s;

        string w = "";
        stack<char> st;
        for(int i = 0; i<s.size(); i++)
        {
            while(s[i] == '(' && i<s.size())
            {
                if(!st.empty())
                {
                    w = w + s[i];
                }
                st.push(s[i]);
                i++;
            }

           while(s[i] == ')' && i<s.size())
            {
                if(st.size() != 1)
                {
                    w = w + s[i];
                    if(st.top() == '(')
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.pop();
                }
                i++;
            }
            i--;
        }
        return w;
    }
};