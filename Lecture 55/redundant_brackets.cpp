#include <bits/stdc++.h> 
using namespace std;
void print(stack<char> st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        if(ch == '(')
        {
            st.push(ch);
            if(s[i+2] == ')')
                return true;
        }
        else if(ch == ')')
        {
            char c = st.top();
            if(c == '(')
                return true;
            else if(c == 'w')
            {
                st.pop();
                char ch1 = st.top();
                if(ch1 == '(')
                    st.pop();
                else
                    return false;
            }
        }
        else
        {
            if(st.empty())
                st.push('w');
            if(st.top() != 'w')
                st.push('w');
        }
    }
    return false;
}
int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    if(findRedundantBrackets(str))
        cout << "True!" << endl;
    else
        cout << "No Redundant Brackets are there" << endl;
    
    return 0;
}