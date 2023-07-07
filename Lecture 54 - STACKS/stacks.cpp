#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Creating Stack under #include <stack>
    stack<int> s;

    // Pushing elements
    s.push(2);
    s.push(3);

    // Top element right now
    cout << s.top() << endl;

    // Poping elements
    s.pop();

    cout << s.top() << endl;

    // Empty or not?
    if(s.empty())
        cout << "Stack is Empty!" << endl;
    else
        cout << "Stack is not empty and this is the top element: " << s.top() << endl;

    cout << "Length of the stack is: " << s.size() << endl;
    return 0;
}