#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter a number: ";
    int n;
    cin >> n;

    cout << "All odd numbers: " << endl;
    for(int i=1; i<=n; i++)
    {
        if(i&1 == 1)
            cout << i << endl;
    }

    // Logic
    // All odd numbers ends with 1 in their binary form, thus doin AND 1, only that last bit decides/remains.
}