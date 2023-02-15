#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int b = 3;

    cout << "a is: " << a << endl;
    cout << "b is: " << b << endl;

    cout << "a&b is: " << (a&b) << endl; //1
    cout << "a|b is: " << (a|b) << endl; //7
    cout << "~a is: " << (~a) << endl; //-6
    cout << "~b is: " << (~b) << endl; //-4
    cout << "a^b is:" << (a^b) << endl; //6

}