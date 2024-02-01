#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Pranit Modi";
    // cout << "Enter Full Name: ";
    // getline(cin,s);

    cout << "Name is: " << s << endl;
    cout << "Length: " << s.length() << endl;
    cout << "First Name: " << s.substr(0,6) << endl;
    cout << "Last Name: " << s.substr(s.length()-4) << endl;
}