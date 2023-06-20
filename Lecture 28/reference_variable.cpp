#include <bits/stdc++.h>
using namespace std;
void update3(int &n)
{
    (n)++;
}
void update2(int *n)
{
    (*n)++;
}
void update1(int n)
{
    n++;
}
int main()
{
    int n=5;

    cout << "Update 1: " << endl; //normal call by value
    cout << "Before: " << n << endl;
    update1(n);
    cout << "After: " << n << endl << endl;

    cout << "Update 2: " << endl;// via pointer
    cout << "Before: " << n << endl;
    update2(&n);
    cout << "After: " << n << endl << endl;

    cout << "Update 3: " << endl; //via reference variable
    cout << "Before: " << n << endl;
    update3(n);
    cout << "After: " << n << endl;

    return 0;
}