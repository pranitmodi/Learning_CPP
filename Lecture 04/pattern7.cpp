#include <iostream>
using namespace std;
int main()
{
    /*
        1
        2       3
        3       4       5
        4       5       6       7
    */
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int i = 1;
    int j;
    int c;

    while(i <= n)
    {
        j = 1;
        c = i;
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