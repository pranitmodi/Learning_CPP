#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch[20];
    cout << "Enter your name: ";
    cin >> ch;

    cout << "Name is: " << ch << endl;
    int l = strlen(ch);
    cout << "Length: " << l << endl;

    char ch2[] = "Pranit";
    if(!strcmp(ch,ch2))
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;

    cout << ch2 << endl;
}