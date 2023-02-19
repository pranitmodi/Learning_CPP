#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter binary number: " << endl;
    cin >> n;

    int dec=0;
    int count = 0;
    while(n != 0)
    {
        int d = n%10;
        if(d == 1)
        {
            dec = dec + (int)pow(2,count);
        }
        count++;
        n = n/10;
    }

    cout << "Decimal Representation is: " << dec << endl;
}