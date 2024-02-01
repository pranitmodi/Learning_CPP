// 20
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) 
{
    if(s.length()&1)
        return false;

    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if(st.empty())
                return false;

            if((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}'))
            {
                st.pop();
            }
            else
                return false;
        }
        else
            st.push(s[i]);
    }

    if(st.empty())
        return true;
    else
        return false;
}