#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Pattern: " << endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=(n-i); j++)
        {
            cout << " " << " ";
        }

        for(int j=i; j>=1; j--)
        {
            cout << j << " ";
        }

        for(int j=2; j<=i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}