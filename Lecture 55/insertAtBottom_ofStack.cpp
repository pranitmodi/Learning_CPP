#include <bits/stdc++.h>
using namespace std;
void print(stack<int> st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void addEle(stack<int>& st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int ele = st.top();
    st.pop();
    addEle(st,x);
    st.push(ele);
}
int main()
{
    int ele;
    cout << "Enter the element to be added: ";
    cin >> ele;

    stack<int> st;
    st.push(4);
    st.push(45);
    st.push(6);
    st.push(78);
    st.push(31);
    st.push(25);
    cout << "Till Now: ";
    print(st);

    addEle(st,ele);
    cout << "Added: " << endl;
    print(st);
}