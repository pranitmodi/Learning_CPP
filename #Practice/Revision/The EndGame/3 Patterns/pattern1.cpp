#include <bits/stdc++.h>
using namespace std;
// A B C 
// B C D 
// C D E 
int main()
{
    int m,n;
    cout << "Enter Values: ";
    cin >> m >> n;

    for(int i=0; i<m; i++)
    {
        char ch = 'A' + i;
        for(int j=0; j<n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}