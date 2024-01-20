// Least Common Multiple (LCM): The LCM of two or more integers is the smallest positive integer that is a multiple of each of the given integers.

// Relationship between GCD and LCM:
// For any two integers a and b, the product of their GCD and LCM is equal to the product of the two integers:
// GCD(a,b) × LCM(a,b) = ∣ a×b ∣

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
    int a = 3;
    int b = 6;
    int lcm = (a*b) / gcd(a,b);
    cout << "LCM: " << lcm << endl;
}