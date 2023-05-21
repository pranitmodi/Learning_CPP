#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout << "Enter the number of elements(has to be a odd number): " << endl;
    cin >> size;

    if(size%2 == 0)
    {
        cout << "You entered an Input number" << endl;
        return 0;
    }

    int arr[20];

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array elements are: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int ans = 0;
    for(int i=0; i<size; i++)
    {
        ans = ans^arr[i];
    }
    cout << "Unique element is: " << ans;

    return 0; 
}