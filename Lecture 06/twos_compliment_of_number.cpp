#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter decimal number: " << endl;
    cin >> n;

    int n1=n;
    int bin = 0;
    int count = 0;
    while (n1!=0)
    {
        int d = n1&1;
        double p = pow(10,count);
        bin = bin + ((int)p * d);
        n1 = n1>>1;
        count++;
    }

    cout << "Binary Representation of " << n << " is: " << bin << endl;

    int bin1=bin;
    int ones = 0;
    count = 0;
    while(bin1!=0)
    {
        int d = bin1 % 10;
        double p = pow(10,count);
        d = (!d);
        ones = ones + ((int)p * d);
        bin1 = bin1/10;
        count++;
    }

    cout << "One's compliment of " << bin << " is: " << ones << endl;

    int ones1 = ones;
    int twos = ones;
    count = 0;

    if(ones1 == 1)
    {
        cout << "Two's compliment of " << bin << " is: 10" << endl;
        return 0;
    }

    while(ones1 != 0)
    {
        int d = ones1 % 10;
        if(d == 0)
        {
            twos = twos + (int)pow(10,count);
            break;
        }
        else if(d == 1)
        {
            twos = ones - (int)pow(10,count);
        }
        ones1 = ones1/10;
        count++;
    }

    cout << "Two's compliment of " << bin << " is: " << twos << endl;
}