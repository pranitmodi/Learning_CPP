#include <iostream>
using namespace std;
int main()
{
    /*
        1
        2       3
        4       5       6
        7       8       9       10
    */
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int i = 1;
    int j;
    int c = 1;

    while(i <= n)
    {
        j = 1;
        while(j <= i)
        {
            cout << c << "\t";
            c++;
            j++;
        }
        i++;
        cout << endl;
    }
    
}