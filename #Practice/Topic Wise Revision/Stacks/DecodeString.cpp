// 394
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(char ch)
    {
        int i = ((int)ch) - 48;
        if(i>=0 && i<=9)
            return true;
        else
            return false;
    }
    string decodeString(string s) 
    {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != ']')
                st.push(s[i]);
            else
            {
                string w = "";
                while(st.top() != '[')
                {
                    w = st.top() + w;
                    st.pop();
                }
                st.pop();

                int l = 0;
                int k = 0;
                while(!st.empty() && check(st.top()))
                {
                    l = (((int)st.top() - 48)*((int) pow(10,k++))) + l;
                    st.pop();
                }
                for(int j=1; j<=l; j++)
                {
                    for(char ch:w)
                    {
                        st.push(ch);
                    }
                }
            }
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