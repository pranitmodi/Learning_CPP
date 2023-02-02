// Print the bigger number out of the two numbers entered by the user.
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    // cout << "Enter the first number:" << endl;
    // cin >> a;
    // cout << "Enter the second number:" << endl;
    // cin >> b;
    cin >> a >> b;

    if(a>b)
    {
        cout << "Bigger number is: " << a << endl;
    }
    else if(b>a)
    {
        cout << "Bigger number is: " << b << endl;
    }
    else
    {
        cout << "Both the numbers are equal." << endl;
    }

}