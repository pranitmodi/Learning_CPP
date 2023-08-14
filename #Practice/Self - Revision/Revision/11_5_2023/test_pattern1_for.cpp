#include <iostream>
using namespace std;
int main()
{
    int r;
    cout << "Enter the number: " << endl;
    cin >> r;
    

    cout << "The pattern: " << endl;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=(r-i+1); j++)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}