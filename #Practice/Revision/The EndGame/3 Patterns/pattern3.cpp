#include <bits/stdc++.h>
using namespace std;
// 1 2 3 4 5 6 6 5 4 3 2 1 
// 1 2 3 4 5 * * 5 4 3 2 1 
// 1 2 3 4 * * * * 4 3 2 1 
// 1 2 3 * * * * * * 3 2 1 
// 1 2 * * * * * * * * 2 1 
// 1 * * * * * * * * * * 1 
int main()
{
    int n;
    cout << "Enter value oh N:";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=(n-i); j++)
        {
            cout << j << " ";
        }

        for(int k=1; k<=i; k++)
        {
            cout << "* *" << " ";
        }

        for(int j=(n-i); j>=1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}