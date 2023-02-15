// Leetcode - 191. Number of 1 Bits
// Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the binary number: " << endl;
    cin >> n;

    cout << "Printing n: " << n << endl;

    int c=0;
    while(n!=0)
    {
        if(n&1) //  AND operator gives 1(TRUE) if last bit is 1
        {
            c++;
        }
        n = n>>1; // Right Shift removes the last bit and shift other bits one place to right
    }
    cout << "Number of 1's: " << c << endl;
}