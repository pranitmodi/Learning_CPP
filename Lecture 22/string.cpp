#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter String: ";
    // cin >> str; //Spaces terminates the input

    // getline(cin, str);

    string s1 = "Hello";
    string s2 = "World";
    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;

    s1 = s1 + ' ';
    s1.append(s2);
    cout << "S1 after concatination: " << s1 << endl;

    cout << "Substring: " << endl;
    cout << s1.substr(0,3) << endl; // Hel
    cout << s1.substr(0,s1.length()) << endl; // Hello World
    cout << s1.substr(3,s1.length()) << endl; // lo World
    cout << s1.substr(3,10) << endl; // lo World
    cout << s1.substr(3,20) << endl; // lo World
    cout << s1.substr(3,7) << endl; // lo Worl

    return 0;
}