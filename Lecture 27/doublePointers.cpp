#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i=5;
    int *p=&i;
    int **p2=&p;

    cout << "Address of i: " << &i << endl << endl;

    cout << "Value of p: " << p << endl;
    cout << "Value of *p: " << *p << endl;
    cout << "Address of &p: " << &p << endl << endl;

    cout << "Value of p2: " << p2 << endl;
    cout << "Value of *p2: " << *p2 << endl;
    cout << "Value of **p2: " << **p2 << endl;
    cout << "Address of &p2: " << &p2 << endl << endl;

    return 0;
}