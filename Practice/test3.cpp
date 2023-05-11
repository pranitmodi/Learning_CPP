#include <iostream>
using namespace std;
int main()
{
    int a = -5;
    int b = 6;

    cout << "a&b : " << (a&b) << endl;
    cout << "a|b : " << (a|b) << endl;
    cout << "a^b : " << (a^b) << endl;
    cout << "~a : " << (~a) << endl;
    cout << "~b : " << (~b) << endl;

    cout << "a<<1 : " << (a<<1) << endl;
    cout << "a<<2 : " << (a<<2) << endl;
    cout << "a<<3 : " << (a<<3) << endl;

    cout << "b>>1 : " << (b>>1) << endl;
    return 0;
}