#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter theory: ";
    double t;
    cin >> t;

    cout << "Enter project: ";
    double p;
    cin >> p;

    double res = ((0.25 * p) + (0.75 * t));
    cout << "Result = " << res;
}