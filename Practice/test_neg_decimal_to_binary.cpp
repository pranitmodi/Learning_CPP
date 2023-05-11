#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a negative decimal: " << endl;
    cin >> n;

    int n1 = abs(n);
    int n2=n1;

    //Taking One's Compliment
    int d;
    int ones=0;
    int count = 0;
    while(n2!=0)
    {
        d = n2&1;
        d = (!d);
        double d1 = pow(10,count);
        ones = ones + ((int)d1 * d);
        count++;
        n2=n2>>1;
    }

    cout << "Ones: " << ones << endl;

    int ones1 = ones;
    count = 0;
    if(ones%10 == 0)
    {
        ones = ones + 1;
    }
    else if(ones%10 == 1)
    {
        while((ones % 10) != 0)
        {
            count++;
            ones = ones / 10;
        }
    }
    ones1 = ones1 / (int)pow(10,count);
    ones1 = (ones1 * (int)pow(10,count)) + (int)pow(10,count);

    cout << "Result: " << ones1 << endl;

    return 0;
}