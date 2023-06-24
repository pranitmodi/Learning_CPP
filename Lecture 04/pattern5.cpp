#include <iostream>
using namespace std;
int main()
{
    /*
        *
        **
        ***
        ****
        *****
    */
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    cout << "The pattern is: " << endl;
    int i = 1;
    int j;
    int c=1;
    while(i <= n)
    {
        j = 1;
        while(j <= i)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}