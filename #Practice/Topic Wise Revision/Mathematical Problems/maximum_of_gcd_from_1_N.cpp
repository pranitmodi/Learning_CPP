// The GCD of N and N / 2 is N / 2 which is the maximum of all GCDs possible for any pair from 1 to N.
// for gcd(a,b) = g
// let b be greater than g, then b >= 2g
// thus from 1 to n, n/2 will be the greatest gcd
#include <bits/stdc++.h>
using namespace std;
int main() // for 1 to N
{
    int n = 8;
    cout << "Maximum GCD: " << (n/2) << endl;
}