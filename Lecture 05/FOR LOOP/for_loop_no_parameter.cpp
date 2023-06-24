#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int i = 1;
    for( ; ; )
    {
        if(i<=n)
        {
            cout << i << endl;
        }
        else
        {
            break;
        }
        i++;
    }
}