#include <bits/stdc++.h>
using namespace std;
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
void addAtBottom(stack<int> &st, int val)
{
    if(st.empty())
    {
        st.push(val);
        return;
    }

    int d = st.top();
    st.pop();

    addAtBottom(st,val);

    st.push(d);
}
void reverse(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }

    int val = st.top();
    st.pop();

    reverse(st);

    addAtBottom(st,val);
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
    reverse(st);
    print(st);
    cout << endl;
}