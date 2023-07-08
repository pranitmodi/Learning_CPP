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
void solve(stack<int> &st, int count, int size)
{
    if(count == size/2)
    {
        st.pop();
        return;
    }

    count++;

    int ele = st.top();
    st.pop();

    solve(st,count,size);

    st.push(ele);
}
int main()
{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(2);
    st.push(8);
    st.push(7);
    cout << "Original Stack: " << endl;
    print(st);

    int count = 0;
    int size = st.size();
    solve(st,count,size);

    cout << "Middle has been removed: " << endl;
    print(st);

    return 0;
}