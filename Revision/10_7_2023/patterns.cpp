#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    cout << "Pattern1 : " << endl;
    char ch = 'A';
    int i = 1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << ch << " ";
            j++;
        }
        cout << endl;
        ch++;
        i++;
    }

    cout << endl << endl;

    cout << "Pattern2: " << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=n-i; j>=1; j--)
        {
            cout << "  ";
        }
        for(int k=i; k>=1; k--)
        {
            cout << k << " ";
        }
        for(int m=2; m<=i; m++)
        {
            cout << m << " ";
        }
        cout << endl;
    }

    return 0;
}