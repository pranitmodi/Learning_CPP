#include <iostream>
using namespace std;
int main()
{
    /*
        1
        2       1
        3       2       1
        4       3       2       1
    */
    int n;
    cout << "Enter the number of rows: " << endl;
    cin >> n;

    int i = 1;
    int j;
    while(i <= n)
    {
        j=i;
        while(j >= 1)
        {
            cout << j << "\t";
            j--;
        }
        cout << endl;
        i++;
    }
}