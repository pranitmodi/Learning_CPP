#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value: " << endl;
    cin >> n;

    int i = 1;
    int j;
    while(i <= n)
    {
        j = 1;
        while(j <= n)
        {
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }
}