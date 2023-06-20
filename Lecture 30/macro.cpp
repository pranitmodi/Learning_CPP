#include <bits/stdc++.h>
using namespace std;
#define area(L,B) (L*B)
#define pi 3.14
#define AREA(r) (pi * r * r)

int main()
{
    cout << "Enter Length and Breadth: " << endl;
    int len, b;
    cin >> len >> b;

    cout << "Rectangle Area: " << area(len,b) << endl;

    int r;
    cout << "Enter Radius: " << endl;
    cin >> r;

    cout << "Circle Area: " << AREA(r) << endl;

    return 0;
}