#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    /*
    ABCDE
    FGHIJ
    KLMNO
    PQRST
    UVWXY
    */

    int i=1;
    int j;
    char ch = 'A';

    while(i<=n)
    {
        j=1;
        while(j<=n)
        {
            cout << ch;
            ch = ch + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}