#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter the number of rows: " << endl;
    cin >> r;
    cout << "Enter the number of columns: " << endl;
    cin >> c;

    int i = 1;
    int j;
    while(i <= r)
    {
        j = 1;
        while(j <= c)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}