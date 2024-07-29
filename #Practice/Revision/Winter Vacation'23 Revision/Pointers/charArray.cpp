#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch[7];
    cout << "Enter: " << endl;
    cin >> ch;

    char *p = ch;
    char *p1 = &ch[0];

    cout << "p: " << p << endl;
    cout << "ch: " << ch << endl;
    cout << "&ch: " << &ch << endl;
    cout << "p1: " << p1 << endl; // never prints the address, always print the whole word until reaches '\0'
}