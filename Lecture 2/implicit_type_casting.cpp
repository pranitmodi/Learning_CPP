#include <iostream>
using namespace std;
int main()
{
    // Int to Char and Vice-Versa - IMPLICIT TYPE CASTING
    int i = 97;
    int d = 123456;
    char ch = 'A';

    char ch1 = i;
    char ch2 = d;
    int i1 = ch;

    cout << ch1 << endl; //a
    cout << ch2 << endl << i1 << endl; // @ 65
    
    // Int to Double and Vice-Versa - EXPLICIT TYPE CASTING
    int a = 21;
    double d1 = a;
    double d2 = 41.5;
    int b = (int) d2; 

    cout << d1 << endl; //21
    cout << b << endl; //41

}