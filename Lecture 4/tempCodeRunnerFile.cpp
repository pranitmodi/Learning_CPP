#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int i = 1;
    int j;
    while(i <= n)
    {
        j = n;
        while(j >= 1)
        {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
}