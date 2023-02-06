#include <iostream>
using namespace std;
int main()
{
    int i =8;
    int a;

    a = (++i) + (--i) + i + (--i);
    cout << "Value of i: " << i << endl;
    cout << "Valuse of a: " << a << endl;

    a = -2;
    int b = 10;
    if(++a) // flase: ++a = 0 (ie a = -1), else always true.
    {
        cout << b;
    }
    else
    {
        cout << ++b;
    }

}