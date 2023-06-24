#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    int i = 2;
    while (i < n)
    {
        if(n % i == 0)
        {
            cout << "Not a prime." << endl;
            return (0);
        }
        else
        {
            i++;
        }
    }
    cout << n << " : It is a prime number!" << endl;
}