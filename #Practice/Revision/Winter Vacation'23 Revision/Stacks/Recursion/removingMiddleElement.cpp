#include <bits/stdc++.h>
using namespace std;
void removeMiddle(stack<int> &st, int s, int c)
{
    if(c == s/2)
    {
        st.pop();
        return;
    }

    int val = st.top();
    st.pop();

    c++;
    removeMiddle(st,s,c);
    st.push(val);
}
void print(stack<int> st)
{
    if(st.empty())
    {
        // cout << endl;
        return;
    }

    int val = st.top();
    st.pop();

    print(st);
    cout << val << " ";
    st.push(val);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    removeMiddle(st,st.size(),0);
    print(st);
    cout << endl;
}