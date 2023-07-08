#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Enter String: ";
    cin >> s;

    // Storing the string in the stack
    stack<char> ch;
    for(int i=0; i<s.length(); i++)
    {
        ch.push(s[i]);
    }

    // printing the top elements of the stack and then popping them
    cout << "Reverse String: ";
    while(!ch.empty())
    {
        cout << ch.top();
        ch.pop();

    }
    cout << endl;
}