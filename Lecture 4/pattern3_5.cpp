#include <iostream>
using namespace std;
int main()
{
    /*
        1234
        123
        12
        1
    */
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int i = 1;
    int j;
    while(i <= n)
    {
        j = 1;
        while(j <= ((n+1)-i))
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}