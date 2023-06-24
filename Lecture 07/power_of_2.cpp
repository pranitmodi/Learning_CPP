// 231. Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    
    //OR Use Set Bits as all the integers with power of 2 has Set Bits = number os 1 in their binary value as 1.

    double d = 0;
    int count = 0;
    while(d <= n)
    {
        d = pow(2,count);
        if(n == d)
        {
            cout << "Yes a power of two: 2^" << count << " = " << n << endl;
            return 0;
        }
        count ++;
    }
    if(d>n)
        cout << "Not a power of two" << endl;
    return 0;
}