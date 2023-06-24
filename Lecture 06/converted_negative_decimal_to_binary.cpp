#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    int n = abs(n);

    int b = 0;
    int count = 0;
    int ones = 0;
    while(n!=0)
    {
        int d = n&1;
        double p = pow(10,count);
        b = b + ((int)p * d);
        d=!d;
        ones = ones + ((int)p * d);
        count ++;
        n = n>>1;
    }

    if(ones == 0)// exceptioal case of all 1111111 in binary and one's come out to be thus 0.
    {
        ones = (int)pow(10,count);
    }

    cout << "Count: " << count << endl;
    cout << "Binary: " << b << endl;
    cout << "One's: " << ones << endl;

    int ones1 = ones;
    int d = ones%10;
    int twos = 0;
    if(d == 0)
    {
        twos = ones + 1;
    }
    else if(d == 1)
    {
        int c = 0;
        while(ones%10 != 0)
        {
            c++;
            ones = ones/10;
        }
        int m = (int)pow(10,c);
        twos = (ones1/m) + m;
    }

    cout << "Two's: ";
    int n3 = twos;
    int ct = 0;
    while(n3!=0) //counting the number of bits in two;s calculated
    {
        ct ++;
        n3=n3/10;
    }

    int r = 32-ct; //To print the 1 in the beginning
    for(int i = 1;i<=r;i++)
    {
        cout << "1";
    }
    int diff = count - ct;
    for(int i = 1;i<=diff;i++) //while converting binary to one's the starting 1 that is convertes to 0, gets disregarded.
    {
        cout << "0";
    }
    cout << twos << endl;
    return 0;
}