// 331. Verify Preorder Serialization of a Binary Tree
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        stack<char> st;
        int i=0;
        while(i<preorder.length())    
        {
            st.push(preorder[i]);
            if(st.size()>=3)
            {
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                if(a == b && a == '#')
                {
                    if(st.top() != '#')
                    {
                        cout << st.top() << endl;
                        st.pop();
                        st.push('#');
                    }
                    else
                    {
                        st.push(b);
                        st.push(a);
                    }
                }
                else
                {
                    st.push(b);
                    st.push(a);
                }
            }

            while(i<preorder.length() && preorder[i] != ',')
                i++;
            i++;
        }
        while(st.size()>=3)
        {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();

            if(a == b && a == '#')
            {
                char c = st.top();
                if(c == '#')
                {
                    st.pop();
                    int w = 1;
                    while(!st.empty() && st.top() == '#')
                    {
                        st.pop();
                        w++;
                    }
                    if(st.empty())
                        return false;

                    st.pop();

                    while(w>0)
                    {
                        st.push('#');
                        w--;
                    }
                }
                else
                    st.pop();

                st.push('#');        
            }
            else
                return false;
        }


        if(st.size() == 1 && st.top() == '#')
            return true;
        else
            return false;
    }
};