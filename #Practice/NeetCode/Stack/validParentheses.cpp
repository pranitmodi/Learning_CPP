// LeetCode - 20
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) 
{
    stack<char>st;
    st.push('a');

    for(char ch:s)
    {
        if(ch == '}' || ch == ']' || ch == ')')
        {
            if(st.top() == 'a')
            {
                return false;
            }
            else
            {
                if((ch == '}' && st.top() == '{') || (ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '('))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            st.push(ch);
        }
    }
    if(st.top() == 'a')
        return true;
    return false;
}