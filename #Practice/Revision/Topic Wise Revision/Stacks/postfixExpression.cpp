#include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(string S)
{
    stack<int> st;
    for(int i=0; i<S.length(); i++)
    {
        if(S[i] >= '0' && S[i] <= '9')
        {
            st.push(S[i] - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            
            if(S[i] == '*')
                st.push(a*b);
            else if(S[i] == '/')
                st.push(a/b);
            else if(S[i] == '+')
                st.push(a+b);
            else
                st.push(a-b);
        }
    }
    return st.top();
}