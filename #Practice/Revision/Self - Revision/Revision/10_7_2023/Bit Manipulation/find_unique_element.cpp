#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    int arr[20];
    cout << "Enter elements:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // x^x = 0 AND x^0=x
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans = ans^arr[i];
    }
    cout << "Unique element is: " << ans << endl; 

    return 0;
}