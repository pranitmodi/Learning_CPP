#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    cout << "First Pattern: " << endl;
    int i=1;
    int j;
    while(i<=n)
    {
        j=1;
        while(j<=(n-i))
        {
            cout << " ";
            j++;
        }

        j=1;
        while(j<=i)
        {
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }

    cout << "Second Pattern: " << endl;
    i=1;
    while(i<=n)
    {
        j=1;
        while(j<=(n-i+1))
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }

    cout << "Third Pattern: " << endl;
    i=1;
    while(i<=n)
    {
        j=1;
        while(j<=(i-1))
        {
            cout << " ";
            j++;
        }

        j=1;
        while(j<=(n-i+1))
        {
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}