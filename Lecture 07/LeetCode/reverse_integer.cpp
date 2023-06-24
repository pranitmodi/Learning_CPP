// 7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter integer: " << endl;
    cin >> n;

    int r = 0;
    while(n != 0)
    {
        int d = n%10;
        if ((r > INT32_MAX/10) || (r < INT32_MAX/10))
        {
            return 0;
        }
        r = (r*10) + d;
        n = n/10;
    }

    cout << "The reverse is: " << r;
    
}