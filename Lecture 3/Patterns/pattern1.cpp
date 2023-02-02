#include <iostream>
using namespace std;
int main()
{
    /*
        ****
        ****
        ****
        ****
    */  

    cout << "The First Pattern:" << endl;
        
    int i = 1;
    int j;
    while (i <= 4)
    {
        j = 1;
        while (j <= 4)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
}