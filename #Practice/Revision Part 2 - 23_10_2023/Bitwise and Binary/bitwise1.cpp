#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 2;
    int b = 3;

    cout << a << " " << b << endl;
    cout << "a&b: " << (a&b) << endl; // AND
    cout << "a|b: " << (a|b) << endl; // OR
    cout << "a^b: " << (a^b) << endl; // XOR - 1 if odd number of 1's

    cout << "~a: " << (~a) << endl; // treats as a negative number, as the first bit is 1, then takes 2's compliment and finally prints -3.

    int c = 5;
    cout << c << " " << "left shift(5<<1): " << (5<<1) << endl;
    cout << c << " " << "left shift(5<<2): " << (5<<2) << endl;

    return 0;
}