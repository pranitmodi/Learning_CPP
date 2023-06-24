#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    cout << "Numbers from 1 to " << n << " are:" << endl;
    int i=1;
    while(i <= n)
    {
        cout << i << endl;
        i++;
    }
}