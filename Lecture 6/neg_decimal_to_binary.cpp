#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the neagative number: " << endl;
    cin >> n;

    int a = abs(n);
    int d;
    int bin = 0;
    int count = 0;
    while(a != 0)
    {
        d = a%2;
        if(d == 1)
            d = 0;
        else  
            d = 1;
        double w = pow(10,count);
        bin += ((int)w *d);
        a = a/2;
        count++;
    }
    cout << bin << endl;
    bin = bin + 1; // NEED TO FIX THIS
    cout << "Binary of the negative number is: " << bin;
}