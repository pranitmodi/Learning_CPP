#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    /*
    A
    BB
    CCC
    DDDD
    */

    int i=1;
    int j;
    char ch = 'A';

    while(i<=n)
    {
        j=1;
        while(j<=i)
        {
            cout << ch;
            j++;
        }
        cout << endl;
        ch = ch + 1;
        i++;
    }
    return 0;
}