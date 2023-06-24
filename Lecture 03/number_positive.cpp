// Number is positive or not?
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number:";
    int n;
    cin >> n;

    if(n>0)
    {
        cout << n << " : Number is Positive!" << endl;
    }
    else
    {
        if(n<0)
        {
            cout << n << " : Number is Negative!" << endl;
        }
        else
        {
            cout << n << " : Number = ZERO." << endl;
        }
    }
}