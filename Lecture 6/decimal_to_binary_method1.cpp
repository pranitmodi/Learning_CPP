// Simple Approach
// Dividing by 2 and storing the remainder

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    int d,a,b;
    int count = 0;
    int bin = 0;
    while(n!=0)
    {
        d = n%2;
        double w = pow(10,count);
        bin += ((int)w * d);
        n = n/2;
        count++;
    }
    cout << "The binary representation is: " << bin << endl;
}