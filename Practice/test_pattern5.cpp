#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter the character in Upper Case: " << endl;
    cin >> ch;

    /*
    J
    IJ
    HIJ
    GHIJ
    FGHIJ
    EFGHIJ
    DEFGHIJ
    CDEFGHIJ
    BCDEFGHIJ
    ABCDEFGHIJ
    */

    int n = (ch - 'A') + 1;
    int i = 1;
    int j;
    while(i<=n)
    {
        j=(n-i+1);
        while(j<=n)
        {
            ch = 'A' + (j-1);
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}