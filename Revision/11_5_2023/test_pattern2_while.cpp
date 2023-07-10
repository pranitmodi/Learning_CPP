#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    /*
    1
    23
    345
    4567
    */

    int i=1;
    int j;

    while(i<=n)
    {
        j=1;
        while(j<=i)
        {
            cout << (i-1+j);
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}