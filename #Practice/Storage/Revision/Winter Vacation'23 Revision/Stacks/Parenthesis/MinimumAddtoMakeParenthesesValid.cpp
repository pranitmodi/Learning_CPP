// 921
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s == "")
            return 0;

        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top() == '(' && s[i] == ')')
            {
                st.pop();
            }
            else
                st.push(s[i]);
        }

        if(st.empty())
            return 0;
        return(st.size());
    }
};