#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number: " << endl;
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cout << i << " ";
    }

    if(n<2)
        return 0;

    cout << endl;
    
    for(int i=2; i<=n; i+=2)
    {
        cout << i << " ";
    }

    return 0;
}