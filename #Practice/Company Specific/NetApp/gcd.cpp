#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b>a)
        gcd(b,a);
        
    if(b == 0)
        return a;
    return gcd(b,a % b);
}
int main()
{
    cout << gcd(24,12) << endl;
    cout << gcd(98,56) << endl;
}