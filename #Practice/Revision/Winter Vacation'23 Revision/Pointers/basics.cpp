#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1 = 10;
    int *ptr_n1 = &n1; // datatype needs to be same

    cout << "Address of n1: " << &n1 << endl;
    cout << "Adress: " << ptr_n1 << endl;
    cout << "Value of n1 via pointer: " << *ptr_n1 << endl;
    cout << "Address of pointer: " << &ptr_n1 << endl;

    int **p = NULL;
    p = &ptr_n1;
    cout << "Value in p: " << p << endl;
    cout << "Value in *p: " << *p << endl;
    cout << "Value in **p: " << **p << endl;
}