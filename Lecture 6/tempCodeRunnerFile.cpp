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
    long bin = 0;
    int count = 0;
    while(a != 0)
    {
        d = a%2;
        double w = pow(10,count);
        bin += ((int)w *d);
        a = a/2;
        count++;
    }
    cout << bin << endl;
    long c = ~bin;
    c = c + 1;
    cout << "Binary of the negative number is: " << c;
}