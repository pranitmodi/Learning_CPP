#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number to be checked for prime: ";
    cin >> n;

    int i;
    int c=0;
    for( i=2; i<n ; i++)
    {
        if( n%i == 0)
        {
            c++;
            break;
        }
    }
    if(c == 0)
    {
        cout << n << " is Prime." << endl;
    }
    else
    {
        cout << n << " is NOT Prime!" << endl;
    }
}