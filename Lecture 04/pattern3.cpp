#include <iostream>
using namespace std;
int main()
{
    /*
        1234
        1234
        1234
        1234
    */
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int i = 1;
    int j;
    while(i <= n)
    {
        j=1;
        while(j <= n)
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }    
}