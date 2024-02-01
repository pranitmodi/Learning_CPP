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
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    print(st);
    cout << endl;
}