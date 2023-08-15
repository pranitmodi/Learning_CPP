#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 34;
    int *p = &a;
    (*p)++;
    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "&p: " << &p << endl;
}