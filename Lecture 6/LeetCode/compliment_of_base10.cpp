// 1009. Complement of Base 10 Integer
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number: " << endl;
    cin >> n;
    int n1=n;

    //Converting it to complimentary binary
    int d;
    int s = 0;
    int count = 0;
    while(n!=0)
    {
        d = n%2;
        if (d == 1)
            s = s + (pow(2,count)*0);
        else if (d == 0)
            s = s + (pow(2,count)*1);
        n = n/2;
        count++;
    }
    if(n1 == 0)
        s = 1;

    cout << "Complimentary Decimal Value is: " << s << endl;
}

/* SUMBITTED CODE
class Solution {
public:
    int bitwiseComplement(int n) {
        int d;
        int s = 0;
        int count = 0;
        if(n == 0)
            return 1;
        while(n!=0)
        {
            d = n%2;
            if (d == 1)
                s = s + (pow(2,count)*0);
            else if (d == 0)
                s = s + (pow(2,count)*1);
            n = n/2;
            count++;
        }
        return s;
    }
};
*/