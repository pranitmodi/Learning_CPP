#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int k = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>i; j--)
        {
            cout << " \t";
        }

        for(int j=1; j<=i; j++)    
        {
            cout << k++ << " \t";
        }
        cout << endl;
    }
}