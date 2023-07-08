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

void addEleAtBottom(stack<int>& st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int ele = st.top();
    st.pop();
    addEleAtBottom(st,x);
    st.push(ele);
}
void reverse(stack<int>& st)
{
    if(st.empty())
        return;

    int ele = st.top();
    st.pop();

    reverse(st);

    // AFTER THE RECURSIVE CALL, because we want the current bottom element to be added at the bottom first
    addEleAtBottom(st,ele);
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

    reverse(st);
    cout << "Reversed: " << endl;
    print(st);
}
