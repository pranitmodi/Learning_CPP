#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    int i = 1;
    int sum = 0;

    // sum of all number from 1 to n.
    // while (i <= n)
    // {
    //     sum = sum + i;
    //     i++;
    // }

    //sum of all even numbers from 1 to n.
    i = 2;
    while (i <= n)
    {
        sum = sum + i;
        i+=2;
    }

    cout << "Sum of numbers from 1 to " << n << " : " << sum << endl; 
}