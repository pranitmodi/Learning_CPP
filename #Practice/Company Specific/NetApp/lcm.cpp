#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b,a % b);
}
int main()
{
    cout << (24*12)/gcd(24,12) << endl;
    cout << (98*56)/gcd(98,56) << endl;
}