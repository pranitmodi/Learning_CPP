// 682
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calc(string s)
    {
        return stoi(s);
    }
    bool check(string s)
    {
        if(s!="+" && s!="D" && s!="C")
        {
            return true;
        }
        return false;
    }
    int calPoints(vector<string>& operations) 
    {
        stack<int> st;
        for(int i=0; i<operations.size(); i++)
        {
            if(check(operations[i]))
            {
                st.push(calc(operations[i]));
            }
            else
            {
                if(operations[i] == "+")
                {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.push(a);

                    st.push(a+b);
                }
                else if(operations[i] == "D")
                {
                    st.push(2*st.top());
                }
                else
                {
                    st.pop();
                }
            }
        }
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};