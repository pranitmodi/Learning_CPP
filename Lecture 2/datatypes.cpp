#include <iostream>
using namespace std;
int main()
{
    int a = 123;
    cout << a << endl;

    char ch ='A';
    cout << ch << endl;

    bool b = false;
    cout << b << endl; //While printing bool, if True then 1 is preinted and if False then 0.
    
    float f = 1.2;
    cout << f << endl;

    int size = sizeof(a);
    cout << "Size of a is:" << size << endl;

    double d = 5/2.0;
    cout << d << endl;
 
    return(0); 
}