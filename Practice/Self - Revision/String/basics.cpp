#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter String: ";
    getline(cin,str);
    // cin >> str;
    cout << str << endl;
    cout << (int)':' << endl;
    cout << (int)'0' << endl;
    cout << (int)'9' << endl;

    char ch = 'w';
    cout << ch - 'a' + 'A' << endl;
    cout << (char)(ch - 'a' + 'A') << endl;
}