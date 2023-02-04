#include <iostream>
using namespace std;
int main()
{
    /*
        1234554321
        1234**4321
        123****321
        12******21
        1********1
    */
    int n;
    cout << "Enter the number of rows: " << endl;
    cin >> n;

    cout << "The Dabangg Pattern is:" << endl;

    int i = 1;
    int j;

    while(i <= n)
    {
        j=1;
        while(j <= (n-i+1))
        {
            cout << j;
            j++;
        }

        j=1;
        while(j <= (i-1))
        {
            cout << "*";
            cout << "*";
            j++;
        }

        j=(n-i+1);
        while(j >= 1)
        {
            cout << j;
            j--;
        }

        cout << endl;
        i++;
    }
}