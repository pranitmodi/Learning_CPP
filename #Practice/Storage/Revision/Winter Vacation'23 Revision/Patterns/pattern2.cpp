#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=(n+1-i); j++)
        {
            cout << j << "\t";
        }

        for(int j=1; j<i; j++)
        {
            cout << "\t" << "\t";
        }

        for(int j=(n+1-i); j>=1; j--)
        {
            cout << j << "\t";
        }
        cout << endl;
    }
}