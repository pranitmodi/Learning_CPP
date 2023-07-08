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

void add(stack<int> &st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }

    int d = st.top();
    if(d < ele)
    {
        st.push(ele);
        return;
    }

    st.pop();
    add(st,ele);

    st.push(d);
}
void sort(stack<int> &st)
{
    if(st.empty())
        return;

    int ele = st.top();
    st.pop();
    sort(st);

    // now elements from the bottom stored in ele, come one by one
    if(st.empty()) // if the stack is empty direct add the element which will act as our point of reference in add
        st.push(ele);
    else
    {
        add(st,ele);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements to be added: ";
    cin >> n;

    cout << "Enter elements: " << endl;
    stack<int> st;
    for(int i=1; i<=n; i++)
    {
        int ele;
        cin >> ele;
        st.push(ele); 
    }
    cout << "Till Now: ";
    print(st);

    sort(st);
    cout << "Sorted: " << endl;
    print(st);
}
