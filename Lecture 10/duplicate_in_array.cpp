#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[20];
    int size;
    cout << "Enter Size: " << endl;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    int ans=0;
    for(int i=0; i<size; i++) // also from 1 to n-1.
    {
       ans = ans^arr[i]^i;
    }

    cout << "Duplicate element: " << ans << endl;

}