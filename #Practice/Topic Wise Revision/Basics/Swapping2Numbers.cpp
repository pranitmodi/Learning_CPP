#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter two numbers: " << endl;
    cout << "Enter A: ";
    int a,b;
    cin >> a;
    cout << "Enter B: ";
    cin >> b;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << "Swapped numbers are: " << a << " and " << b << endl;
}