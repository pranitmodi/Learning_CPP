#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements:" << endl;
    for(int i=0; i<n; i++)
    {
        //works both ways
        cin >> *(arr + i);
        // cin >> arr[i];
    } 

    cout << "Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    return 0;
}