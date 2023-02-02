#include <iostream>
using namespace std;
int main()
{
    /*
        54321
        54321
        54321
        54321
        54321
    */
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int i = 1;
    int j;
    while(i <= n)
    {
        j = n;
        while(j >= 1)
        {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}