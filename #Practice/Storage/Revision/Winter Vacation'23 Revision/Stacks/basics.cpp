#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;

    st.push(23);
    st.push(3);

    cout << "Is Empty?: " << st.empty() << endl;

    cout << "Size: " << st.size() << endl;

    cout << "Top: " << st.top() << endl;

    st.pop();
    st.pop();

    cout << "Is Empty?: " << st.empty() << endl;
}