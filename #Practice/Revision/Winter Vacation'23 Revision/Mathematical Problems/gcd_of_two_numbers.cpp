// Greatest Common Divisor (GCD): The GCD of two or more integers is the largest positive integer that divides each of the given integers without leaving a remainder.
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    return gcd(b,a%b);
}
int main()
{   
    // 3%6 = 3
    cout << "GCD: " << gcd(3,6) << endl;
}
