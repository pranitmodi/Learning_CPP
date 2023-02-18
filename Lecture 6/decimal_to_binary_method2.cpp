// Advance Approach
// Using AND operator and Right Shift

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    int d;
    int count = 0;
    int bin = 0;
    while(n!=0)
    {
        d = n&1;  //Using AND Operator
        double w = pow(10,count);
        bin += ((int)w * d);
        n = n>>1; //Right Shift
        count++;
    }
    cout << "The binary representation is: " << bin << endl;
}