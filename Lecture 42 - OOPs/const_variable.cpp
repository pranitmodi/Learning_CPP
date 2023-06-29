#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 9;
    const int *y = &x; //const value
    int* const f = &x; //const pointer
    const int* const i = &x; // const pointer, const value

    *f = 89; //this works when pointer is declared like this - int* const
    cout << "*f: " << *f << endl;

    cout << *y << endl;
    x = 5;
    cout << *y << endl;

    return 0;
}