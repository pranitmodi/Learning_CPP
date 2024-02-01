// The LCM of two consecutive elements is equal to their multiples then it is obvious that the maximum LCM will be of the pair (N, N – 1) i.e. (N * (N – 1)).
#include <bits/stdc++.h>
using namespace std;
int main() // for 1 to N
{
    int n = 8;
    cout << "Maximum GCD: " << (n * (n-1)) << endl;
}